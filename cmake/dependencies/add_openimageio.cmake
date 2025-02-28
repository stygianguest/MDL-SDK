#*****************************************************************************
# Copyright (c) 2022, NVIDIA CORPORATION. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#  * Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#  * Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#  * Neither the name of NVIDIA CORPORATION nor the names of its
#    contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
# EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
# OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#*****************************************************************************

# -------------------------------------------------------------------------------------------------
# script expects the following variables:
# - __TARGET_ADD_DEPENDENCY_TARGET
# - __TARGET_ADD_DEPENDENCY_DEPENDS
# - __TARGET_ADD_DEPENDENCY_COMPONENTS
# - __TARGET_ADD_DEPENDENCY_NO_RUNTIME_COPY
# - __TARGET_ADD_DEPENDENCY_NO_LINKING
# -------------------------------------------------------------------------------------------------

# assuming the find_openiamgeio_ext script was successful
# if not, this is an error case. The corresponding project should not have been selected for build.
if(NOT MDL_OPENIMAGEIO_FOUND)
    message(FATAL_ERROR "The dependency \"${__TARGET_ADD_DEPENDENCY_DEPENDS}\" for target \"${__TARGET_ADD_DEPENDENCY_TARGET}\" could not be resolved.")
else()

    # add the include directory
    target_include_directories(${__TARGET_ADD_DEPENDENCY_TARGET}
        PRIVATE
            ${MDL_DEPENDENCY_OPENIMAGEIO_INCLUDE}
        )

    # link static/shared object
    if(NOT __TARGET_ADD_DEPENDENCY_NO_LINKING)
        if(WINDOWS)
            # static library (part)
            target_link_libraries(${__TARGET_ADD_DEPENDENCY_TARGET}
                PRIVATE
                    ${LINKER_WHOLE_ARCHIVE}
                    OpenImageIO::OpenImageIO
                    TIFF::TIFF
                    liblzma::liblzma
                    ${LINKER_NO_WHOLE_ARCHIVE}
                )
        else()
            # shared library
            target_link_libraries(${__TARGET_ADD_DEPENDENCY_TARGET}
                PRIVATE
                    ${LINKER_NO_AS_NEEDED}
                    OpenImageIO::OpenImageIO
                    # Explicitly add TIFF library here to avoid that it first
                    # appears (as dependency of OIIO) after LZMA below.
                    TIFF::TIFF
                    # Necessary to avoid undefined symbols in TIFF library.
                    liblzma::liblzma
                    ${LINKER_AS_NEEDED}
                )
        endif()
    endif()

    # copy runtime dependencies
    # copy system libraries only on windows, we assume the libraries are installed in a unix environment
    if(NOT __TARGET_ADD_DEPENDENCY_NO_RUNTIME_COPY AND WINDOWS)
        get_target_property(PROPERTY_LOCATION OpenImageIO::OpenImageIO LOCATION)
        target_copy_to_output_dir(TARGET ${__TARGET_ADD_DEPENDENCY_TARGET}
            FILES
                ${PROPERTY_LOCATION}
            )
    endif()
endif()
