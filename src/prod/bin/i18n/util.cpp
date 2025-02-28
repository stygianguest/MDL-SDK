/***************************************************************************************************
 * Copyright (c) 2018-2022, NVIDIA CORPORATION. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *  * Neither the name of NVIDIA CORPORATION nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 **************************************************************************************************/
#include "util.h"
#include "application.h"
#include "errors.h"
#include <base/hal/hal/i_hal_ospath.h>
#include <base/hal/disk/i_disk_file.h>
#include <base/hal/disk/disk.h>
#include <base/hal/hal/hal.h>
#include <base/util/string_utils/i_string_utils.h>
#include <iostream>
#include <ostream>
#include <fstream>   
using namespace i18n;
using std::vector;
using std::string;
using std::cout;
using std::cerr;
using std::endl;

/// File
bool Util::File::Test()
{
    string new_filename;
    {
        std::string folder("c:\\temp");
        Util::File file(folder);
        std::string newtempfile;
        if (file.is_directory())
        {
            newtempfile = Util::unique_file_in_folder(file.get_directory());
            Util::File file(newtempfile);
            check_success3(false == file.exist(), Errors::ERR_UNIT_TEST, "Util::File::Test()");

            {
                MI::DISK::File dummy;
                dummy.open(newtempfile, MI::DISK::File::Mode::M_WRITE);
                dummy.writeline("");
                dummy.close();
            }
            check_success3(true == file.exist(), Errors::ERR_UNIT_TEST, "Util::File::Test()");
            check_success3(true == file.is_file(), Errors::ERR_UNIT_TEST, "Util::File::Test()");
            check_success3(false == file.is_directory(), Errors::ERR_UNIT_TEST, "Util::File::Test()");

            bool is_empty(file.is_empty());
            check_success3(true == is_empty, Errors::ERR_UNIT_TEST, "Util::File::Test()");

            bool equivalent(Util::equivalent("c:\\temp\\..\\temp\\foobar", "c:\\temp\\foobar"));
            check_success3(true == equivalent, Errors::ERR_UNIT_TEST, "Util::File::Test()");

            std::string new_folder(path_appends(folder, "F2435087-4819-4415-911E-22BB8E6C1DC9"));
            if (Util::create_directory(new_folder))
            {
                Util::File file(new_folder);
                is_empty = file.is_empty();
                check_success3(true == is_empty, Errors::ERR_UNIT_TEST, "Util::File::Test()");

                bool sucess = Util::copy_file(newtempfile, new_folder);
                check_success3(true == sucess, Errors::ERR_UNIT_TEST, "Util::File::Test()");

                file.remove();
                check_success3(true == is_empty, Errors::ERR_UNIT_TEST, "Util::File::Test()");
            }
            file.remove();
        }

        std::string stem = Util::stem("/foo/bar.txt");
        check_success3(stem == "bar", Errors::ERR_UNIT_TEST, "Util::File::Test()");
        stem = Util::stem("foo.bar.baz.tar.txt");
        check_success3(stem == "foo.bar.baz.tar", Errors::ERR_UNIT_TEST, "Util::File::Test()");
        stem = Util::stem("foo.bar.baz.tar.txt/");
        check_success3(stem == "", Errors::ERR_UNIT_TEST, "Util::File::Test()");
        string basename(Util::basename("c:/temp/foo.bar.baz.tar.txt"));
        check_success3(basename == "foo.bar.baz.tar.txt", Errors::ERR_UNIT_TEST, "Util::File::Test()");
    }
    return true;
}

Util::File::File(const string& path)
    : m_path(path)
{}

bool Util::File::exist() const
{
    if (Util::File::is_file())
    {
        MI::DISK::File diskfile;
        return diskfile.open(m_path);
    }
    if (Util::File::is_directory())
    {
        MI::DISK::Directory dir;
        return dir.open(m_path.c_str());
    }
    return false;
}

bool Util::File::remove() const
{
    if (Util::File::is_file())
    {
        return MI::DISK::file_remove(m_path.c_str());
    }
    if (Util::File::is_directory())
    {
        // NOTE: directory need to be empty, we do not handle non empty dir
        return MI::DISK::rmdir(m_path.c_str());
    }
    return false;
}

bool Util::File::is_file() const
{
    MI::DISK::File diskfile;
    if (diskfile.open(m_path))
    {
        return (diskfile.is_file());
    }
    return false;
}

bool Util::File::is_directory() const
{
    MI::DISK::Directory diskdir;
    return diskdir.open(m_path.c_str());
}

bool Util::File::is_readable() const
{
    bool readable = false;
    if (is_directory())
    {
        Util::log_warning("+++++++++++++TODO: Implement Util::File::is_readable() for directories");
    }
    else if (is_file())
    {
        std::ifstream file(
            m_path.c_str(), std::ios::in | std::ios::binary | std::ios::ate);
        if (file.is_open())
        {
            readable = true;
            file.close();
        }
    }
    return readable;
}

bool Util::File::is_writable() const
{
    bool writable = false;
    if (is_directory())
    {
        // try to write in the location
        //std::string filePath = Util::path_appends(m_path, Util::unique_path("%%%%-%%%%-%%%%-%%%%"/*model*/));
        std::string filePath = Util::unique_file_in_folder(m_path);
        Util::File temp_directory(filePath);
        std::ofstream outfile(filePath.c_str());
        outfile << "Test write" << std::endl;
        outfile.close();
        if (!outfile.fail() && !outfile.bad())
        {
            writable = true;
        }
        temp_directory.remove();
        Util::log_debug(
            m_path + (writable ? " is writable" : " is not writable"));
    }
    else if (is_file())
    {
        std::ifstream file(
            m_path, std::ios::out | std::ios::binary | std::ios::ate);
        if (file.is_open())
        {
            writable = true;
            file.close();
        }
    }
    return writable;
}

bool Util::File::size(mi::Sint64 & rtnsize) const
{
    rtnsize = 0;
    if (Util::File::is_directory())
    {
        MI::DISK::Directory dir;
        if (dir.open(m_path.c_str()))
        {
            while (!dir.read(true/*nodot*/).empty())
            {
                rtnsize++;
            }
            return true;
        }
    }
    MI::DISK::File diskfile;
    if (diskfile.open(m_path))
    {
        if (diskfile.is_file())
        {
            rtnsize = diskfile.filesize();
            return true;
        }
    }
    return false;
}

bool Util::File::is_empty() const
{
    if (Util::File::is_directory())
    {
        MI::DISK::Directory dir;
        if (!dir.open(m_path.c_str()))
        {
            return false;
        }
        std::string fn = dir.read(true/*nodot*/);
        return fn.empty();
    }
    MI::DISK::File diskfile;
    if (diskfile.open(m_path))
    {
        if (diskfile.is_file())
        {
            return 0 == diskfile.filesize();
        }
    }
    return false;
}

std::string Util::File::get_directory() const
{
    if (Util::File::is_directory())
    {
        return m_path;
    }
    MI::DISK::File diskfile;
    if (diskfile.open(m_path))
    {
        if (diskfile.is_file())
        {
            return MI::HAL::Ospath::dirname(m_path);
        }
    }
    return "";
}

/// log
void log(const string & msg)
{
    cerr << msg << endl;
}

void log_internal(
    const mi::base::Handle<mi::base::ILogger> & logger
    , const string & msg
    , mi::base::Message_severity level
)
{
    if (logger)
    {
        logger->message(level, "MDLM", msg.c_str());
    }
    else
    {
#if ! defined(DEBUG)
        // Iray not started
        // In release build, do not log message which level is not at least warning
        if (level <= mi::base::MESSAGE_SEVERITY_WARNING)
#endif
        {
            log(msg);
        }
    }
}

void Util::log_fatal(const string & msg)
{
    log_internal(Application::theApp().logger(), msg, mi::base::MESSAGE_SEVERITY_FATAL);
}

void Util::log_error(const string & msg)
{
    log_internal(Application::theApp().logger(), msg, mi::base::MESSAGE_SEVERITY_ERROR);
}

void Util::log_warning(const string & msg)
{
    log_internal(Application::theApp().logger(), msg, mi::base::MESSAGE_SEVERITY_WARNING);
}

void Util::log_info(const string & msg)
{
    log_internal(Application::theApp().logger(), msg, mi::base::MESSAGE_SEVERITY_INFO);
}

void Util::log_verbose(const string & msg)
{
    log_internal(Application::theApp().logger(), msg, mi::base::MESSAGE_SEVERITY_VERBOSE);
}

void Util::log_debug(const string & msg)
{
    log_internal(Application::theApp().logger(), msg, mi::base::MESSAGE_SEVERITY_DEBUG);
}

void Util::log(const std::string & msg, mi::base::Message_severity severity)
{
    log_internal(Application::theApp().logger(), msg, severity);
}

void Util::log_report(const std::string & msg)
{
    cout << msg << endl;
}

string Util::basename(const string& path)
{
    return MI::HAL::Ospath::basename(path);
}

string Util::extension(const std::string& path)
{
    return MI::HAL::Ospath::get_ext(path);
}

string Util::get_program_name(const string & path)
{
    string res = Util::basename(path);

#ifdef MI_PLATFORM_WINDOWS
    size_t l = res.length();
    if (l >= 4 && res.substr(l - 4) == ".exe")
    {
        res = res.substr(0, l - 4);
    }
#endif
    return res;
}

bool Util::file_is_readable(const string & path)
{
    Util::File file(path);
    return file.is_readable();
}

bool Util::directory_is_writable(const string & path)
{
    Util::File directory(path);
    return directory.is_directory() && directory.is_writable();
}

bool Util::create_directory(const string & new_directory)
{
    return MI::DISK::mkdir(new_directory.c_str());
}

bool Util::delete_file_or_directory(const string & file_or_directory, bool recursive)
{
    Util::File file(file_or_directory);
    if (file.is_directory() && recursive)
    {
        MI::DISK::Directory dir;
        if (dir.open(file_or_directory.c_str()))
        {
            while (true)
            {
                string elem(dir.read(true/*nodot*/));
                if (elem.empty())
                {
                    break;
                }
                Util::delete_file_or_directory(
                    Util::path_appends(file_or_directory, elem)
                    , recursive);
            }
        }
    }
    return file.remove();
}

bool Util::has_ending(string const &fullString, string const &ending)
{
    if (fullString.length() >= ending.length())
    {
        return (
            0 == fullString.compare(
                fullString.length() - ending.length(), ending.length(), ending));
    }
    else
    {
        return false;
    }
}

bool Util::remove_duplicate_directories(vector<string> & directories)
{
    bool modified = false;
    try
    {
        vector<string>::const_iterator it = directories.begin();
        while (it != directories.end())
        {
            vector<string>::const_iterator it2 = it;
            it2++;
            while (it2 != directories.end())
            {
                if (Util::equivalent(*it, *it2))
                {
                    Util::log_info("Duplicate MDL directory ignored: " + *it2);
                    it2 = directories.erase(it2);
                    modified = true;
                }
                else
                {
                    it2++;
                }
            }
            it++;
        }
        return modified;
    }
    catch (std::exception& e)
    {
        Util::log_error("Remove duplicate directory: " + std::string(e.what()));
    }
    catch (...)
    {
        Util::log_error("Remove duplicate directory: Exception of unknown type");
    }
    return modified;
}

/// Copy file
bool Util::copy_file(std::string const & source, std::string const & destination)
{
    return MI::DISK::file_copy(source.c_str(), destination.c_str());
}

void Util::array_to_vector(int ac, char *av[], vector<string> & v)
{
    v.clear();
    for (int i = 0; i < ac; i++)
    {
        v.push_back(av[i]);
    }
}

string Util::normalize(const std::string & path)
{
    return MI::HAL::Ospath::normpath(path);
}

bool Util::equivalent(const std::string & file1, const std::string & file2)
{
    std::string p1(file1);
    if (!MI::DISK::is_path_absolute(p1))
    {
        p1 = Util::path_appends(MI::DISK::get_cwd(), file1);
    }
    std::string p2(file2);
    if (!MI::DISK::is_path_absolute(p2))
    {
        p2 = Util::path_appends(MI::DISK::get_cwd(), file2);
    }

    std::string p1norm(Util::normalize(p1));
    std::string p2norm(Util::normalize(p2));

#if WIN_NT
    // On Windows, normalize the case before testing
    MI::STRING::to_upper(p1norm);
    MI::STRING::to_upper(p2norm);
#endif

    return p1norm == p2norm;
}

std::string Util::path_appends(const std::string & path, const std::string & end)
{
    return MI::HAL::Ospath::join(path, end);
}

std::string Util::stem(const std::string & path)
{
    std::string head;
    std::string tail;

    MI::HAL::Ospath::split(path, head, tail);

    if (!tail.empty())
    {
        std::string root;
        std::string ext;
        MI::HAL::Ospath::splitext(tail, root, ext);
        return root;
    }

    return "";
}

std::string Util::unique_file_in_folder(const std::string & folder)
{
    std::string prefix("BAA0A38F-3889-4A44-9C4D-852534E6AAA8");
    std::string filename(prefix);
    int i = 1;
    while (true)
    {
        std::string full_name(path_appends(folder, filename));
        Util::File file(full_name);
        if (file.exist())
        {
            std::stringstream str;
            str << prefix;
            str << i++;
            filename = str.str();
        }
        else
        {
            return full_name;
        }
    }
}
