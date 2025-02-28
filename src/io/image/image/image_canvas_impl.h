/***************************************************************************************************
 * Copyright (c) 2011-2022, NVIDIA CORPORATION. All rights reserved.
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

#ifndef IO_IMAGE_IMAGE_IMAGE_CANVAS_IMPL_H
#define IO_IMAGE_IMAGE_IMAGE_CANVAS_IMPL_H

#include <mi/neuraylib/icanvas.h>

#include <mi/base/interface_implement.h>
#include <mi/base/handle.h>
#include <mi/base/lock.h>

#include "i_image_utilities.h"

#include <string>
#include <vector>
#include <boost/core/noncopyable.hpp>

namespace mi { namespace neuraylib { class IBuffer; class IImage_file; class IReader; } }

namespace MI {

namespace IMAGE {

/// IMAGE::ICanvas is an interface derived from mi::neuraylib::ICanvas.
///
/// It adds two methods for the cubemap flag and to compute the memory usage of the tile. Always use
/// the public interface, unless you really need these special methods.
class ICanvas : public
    mi::base::Interface_declare<0x51c267a7,0x03b7,0x4b85,0x97,0xbc,0x46,0xee,0x0b,0x59,0x26,0x35,
                                mi::neuraylib::ICanvas>
{
public:
    /// Indicates whether this canvas represents a cubemap.
    virtual bool get_is_cubemap() const = 0;

    /// Returns the memory used by this element in bytes, including all substructures.
    ///
    /// Used to implement DB::Element_base::get_size() for DBIMAGE::Image.
    virtual mi::Size get_size() const = 0;

    /// Releases the allocated tile memory.
    ///
    /// \return   \c true on success, \c false, if the canvas does not support lazy loading and
    ///           therefore cannot simply free its data.
    virtual bool release_tiles() const = 0;
};

/// A simple implementation of the ICanvas interface.
///
/// The canvas is either file-based (constructed from a file name), or archive-based (constructed
/// from a reader and archive file/member name), or memory-based (constructed from parameters like
/// pixel type, width, height, etc.). File-based or archive-based canvases load the tile data lazily
/// when needed. Memory-based canvases create all tiles right in the constructor.
///
/// File-based or archive-based canvases could flush unused tiles if memory gets tight (not yet
/// implemented).
class Canvas_impl final // constructor invokes virtual method calls
  : public mi::base::Interface_implement<ICanvas>,
    public boost::noncopyable
{
public:
    /// Constructor.
    ///
    /// Creates a memory-based canvas with given pixel type, width, height, and layers.
    ///
    /// \param pixel_type         The desired pixel type.
    /// \param width              The desired width.
    /// \param height             The desired height.
    /// \param layers             The desired number of layers (depth).
    /// \param is_cubemap         Flag that indicates whether this mipmap represents a cubemap.
    /// \param gamma              The desired gamma value. The special value 0.0 represents the
    ///                           default gamma which is 1.0 for HDR pixel types and 2.2 for LDR
    ///                           pixel types.
    Canvas_impl(
        Pixel_type pixel_type,
        mi::Uint32 width,
        mi::Uint32 height,
        mi::Uint32 layers,
        bool is_cubemap,
        mi::Float32 gamma);

    /// Constructor.
    ///
    /// Creates a memory-based copy of another canvas.
    ///
    /// \param other              The canvas to copy from.
    Canvas_impl( const mi::neuraylib::ICanvas* other);

    /// Constructor.
    ///
    /// Creates a file-based canvas that represents the given file on disk (or a pink dummy 1x1
    /// canvas in case of errors).
    ///
    /// \param filename           The file that shall be represented by this canvas.
    /// \param selector           The selector, or \c NULL.
    /// \param miplevel           The miplevel in the file that shall be represented by this canvas.
    /// \param image_file         An optional pointer to the file \p filename. If the calling code
    ///                           has such a pointer, it can be passed to avoid opening the file
    ///                           once again.
    /// \param errors[out]        An optional pointer to an #mi::Sint32 to which an error code will
    ///                           be written. The error codes have the following meaning:
    ///                           -  0: Success.
    ///                           - -3: Failure to open the file.
    ///                           - -4: No image plugin found to handle the file.
    ///                           - -5: The image plugin failed to import the file.
    Canvas_impl(
        const std::string& filename,
        const char* selector,
        mi::Uint32 miplevel,
        mi::neuraylib::IImage_file* image_file = 0,
        mi::Sint32* errors = 0);

    /// Constructor.
    ///
    /// Creates an archive-based mipmap obtained from a reader (or a pink dummy 1x1 canvas in case
    /// of errors).
    ///
    /// \param reader             The reader to be used to obtain the canvas. Needs to support
    ///                           absolute access.
    /// \param archive_filename   The resolved filename of the archive itself.
    /// \param member_filename    The relative filename of the canvas in the archive.
    /// \param selector           The selector, or \c NULL.
    /// \param miplevel           The miplevel in the file that shall be represented by this canvas.
    /// \param image_file         An optional pointer to the file represented by \p reader. If the
    ///                           calling code has such a pointer, it can be passed to avoid opening
    ///                           the file once again.
    /// \param errors[out]        An optional pointer to an #mi::Sint32 to which an error code will
    ///                           be written. The error codes have the following meaning:
    ///                           -  0: Success.
    ///                           - -3: Invalid reader, or the reader does not support absolute
    ///                                 access.
    ///                           - -4: No image plugin found to handle the data.
    ///                           - -5: The image plugin failed to import the data.
    Canvas_impl(
        Container_based,
        mi::neuraylib::IReader* reader,
        const std::string& archive_filename,
        const std::string& member_filename,
        const char* selector,
        mi::Uint32 miplevel,
        mi::neuraylib::IImage_file* image_file = 0,
        mi::Sint32* errors = 0);

    /// Constructor.
    ///
    /// Creates a memory-based canvas that represents the given file in memory (or a pink dummy 1x1
    /// canvas in case of errors).
    ///
    /// \param reader             The reader to be used to obtain the canvas. Needs to support
    ///                           absolute access.
    /// \param image_format       The image format of the buffer.
    /// \param selector           The selector, or \c NULL.
    /// \param mdl_file_path      The resolved MDL file path (to be used for log messages only),
    ///                           or \c NULL in other contexts.
    /// \param miplevel           The miplevel in the buffer that shall be represented by this
    ///                           canvas.
    /// \param image_file         An optional pointer to the file represented by \p reader. If the
    ///                           calling code has such a pointer, it can be passed to avoid opening
    ///                           the file once again.
    /// \param errors[out]        An optional pointer to an #mi::Sint32 to which an error code will
    ///                           be written. The error codes have the following meaning:
    ///                           -  0: Success.
    ///                           - -3: Invalid reader, or the reader does not support absolute
    ///                                 access.
    ///                           - -4: No image plugin found to handle the data.
    ///                           - -5: The image plugin failed to import the data.
    Canvas_impl(
        Memory_based,
        mi::neuraylib::IReader* reader,
        const char* image_format,
        const char* selector,
        const char* mdl_file_path,
        mi::Uint32 miplevel,
        mi::neuraylib::IImage_file* image_file = 0,
        mi::Sint32* errors = 0);

    /// Constructor.
    ///
    /// Creates a memory-based canvas with a given array of tile.
    ///
    /// \param tile         The array of tiles the canvas will be made of (in z-direction). Note
    ///                     that the tiles are not copied, but shared. See
    ///                     Image_module::copy_tile() if sharing is not desired.
    /// \param gamma        The desired gamma value. The special value 0.0 represents the default
    ///                     gamma which is 1.0 for HDR pixel types and 2.2 for LDR pixel types.
    ///                     Note that the pixel data itself is not changed.
    Canvas_impl(
        const std::vector<mi::base::Handle<mi::neuraylib::ITile>>& tiles, mi::Float32 gamma = 0.0f);

    // methods of mi::neuraylib::ICanvas_base

    mi::Uint32 get_resolution_x() const { return m_width; }

    mi::Uint32 get_resolution_y() const { return m_height; }

    const char* get_type() const;

    mi::Uint32 get_layers_size() const { return m_nr_of_layers; }

    mi::Float32 get_gamma() const { return m_gamma; }

    void set_gamma( mi::Float32 gamma);

    // methods of  mi::neuraylib::ICanvas

    const mi::neuraylib::ITile* get_tile( mi::Uint32 layer = 0) const;

    mi::neuraylib::ITile* get_tile( mi::Uint32 layer = 0);

    // methods of IMAGE::ICanvas

    bool get_is_cubemap() const { return m_is_cubemap; }

    mi::Size get_size() const;

    bool release_tiles() const;

private:
    /// Indicates whether this canvas supports lazy loading.
    bool supports_lazy_loading() const;

    /// Loads the tile data for file-based canvases.
    ///
    /// Wrapper around #do_load_tile() to handle the failure cases.
    ///
    /// \param z      The z position of the tile in the canvas.
    /// \return       The loaded tile, or a dummy tile in case of failures.
    ///
    /// \note The caller needs to hold the lock m_lock.
     mi::neuraylib::ITile* load_tile( mi::Uint32 z) const;

    /// Really loads the tile data for file-based canvases.
    ///
    /// \param z      The z position of the tile in the canvas.
    /// \return       The loaded tile, or \c NULL in case of failures.
    ///
    /// \note The caller needs to hold the lock m_lock.
     mi::neuraylib::ITile* do_load_tile( mi::Uint32 z) const;

    /// Returns the reader used by #load_tile();
    mi::neuraylib::IReader* get_reader( std::string& log_identifier) const;

    /// Sets the canvas to a dummy canvas with a 1x1 tile with a pink pixel.
    void set_default_pink_dummy_canvas();

    /// Pixel type of the canvas
    Pixel_type m_pixel_type;
    /// Width of the canvas
    mi::Uint32 m_width;
    /// Height of the canvas
    mi::Uint32 m_height;
    /// Number of layers of the canvas
    mi::Uint32 m_nr_of_layers;
    /// The represented miplevel (only used for file-based canvases)
    mi::Uint32 m_miplevel;
    /// Flag for cubemaps
    bool m_is_cubemap;
    /// Gamma value
    mi::Float32 m_gamma;

    /// The tiles of this canvas.
    ///
    /// Might contain \c NULL pointers for not yet loaded tiles for file-based canvases. Never
    /// contains \c NULL pointers for memory-based canvases.
    ///
    /// \note Any access needs to be protected by m_lock.
    mutable std::vector<mi::base::Handle<mi::neuraylib::ITile>> m_tiles;

    /// The lock that protects m_tiles;
    mutable mi::base::Lock m_lock;

    /// The file used to load this canvas.
    ///
    /// Non-empty for file-based canvases, empty for memory-based canvases (including archives).
    std::string m_filename;

    /// The archive file used to load this canvas.
    ///
    /// Non-empty for memory-based canvases from archives, empty for other memory-based canvases
    /// and file-based canvases.
    std::string m_archive_filename;

    /// The archive member file used to load this canvas.
    ///
    /// Non-empty for memory-based canvases from archives, empty for other memory-based canvases
    /// and file-based canvases.
    std::string m_member_filename;

    /// The selector (or empty).
    std::string m_selector;
};

} // namespace IMAGE

} // namespace MI

#endif // MI_IO_IMAGE_IMAGE_IMAGE_CANVAS_IMPL_H
