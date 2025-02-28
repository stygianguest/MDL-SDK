/***************************************************************************************************
 * Copyright (c) 2012-2022, NVIDIA CORPORATION. All rights reserved.
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
/// \file
/// \brief Typedefs for types from the math API

#ifndef MI_NEURAYLIB_MATRIX_TYPEDEFS_H
#define MI_NEURAYLIB_MATRIX_TYPEDEFS_H

#include <mi/math/matrix.h>

namespace mi {

/** \addtogroup mi_neuray_compounds
@{
*/

/// 2 x 2 matrix of bool.
///
/// \see #mi::Boolean_2_2_struct for the corresponding POD type and
///      #mi::math::Matrix for the underlying template class
typedef math::Matrix<bool,2,2> Boolean_2_2;

/// 2 x 3 matrix of bool.
///
/// \see #mi::Boolean_2_3_struct for the corresponding POD type and
///      #mi::math::Matrix for the underlying template class
typedef math::Matrix<bool,2,3> Boolean_2_3;

/// 2 x 4 matrix of bool.
///
/// \see #mi::Boolean_2_4_struct for the corresponding POD type and
///      #mi::math::Matrix for the underlying template class
typedef math::Matrix<bool,2,4> Boolean_2_4;

/// 3 x 2 matrix of bool.
///
/// \see #mi::Boolean_3_2_struct for the corresponding POD type and
///      #mi::math::Matrix for the underlying template class
typedef math::Matrix<bool,3,2> Boolean_3_2;

/// 3 x 3 matrix of bool.
///
/// \see #mi::Boolean_3_3_struct for the corresponding POD type and
///      #mi::math::Matrix for the underlying template class
typedef math::Matrix<bool,3,3> Boolean_3_3;

/// 3 x 4 matrix of bool.
///
/// \see #mi::Boolean_3_4_struct for the corresponding POD type and
///      #mi::math::Matrix for the underlying template class
typedef math::Matrix<bool,3,4> Boolean_3_4;

/// 4 x 2 matrix of bool.
///
/// \see #mi::Boolean_4_2_struct for the corresponding POD type and
///      #mi::math::Matrix for the underlying template class
typedef math::Matrix<bool,4,2> Boolean_4_2;

/// 4 x 3 matrix of bool.
///
/// \see #mi::Boolean_4_3_struct for the corresponding POD type and
///      #mi::math::Matrix for the underlying template class
typedef math::Matrix<bool,4,3> Boolean_4_3;

/// 4 x 4 matrix of bool.
///
/// \see #mi::Boolean_4_4_struct for the corresponding POD type and
///      #mi::math::Matrix for the underlying template class
typedef math::Matrix<bool,4,4> Boolean_4_4;



/// 2 x 2 matrix of %Sint32.
///
/// \see #mi::Sint32_2_2_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Sint32 for the type of the matrix components
typedef math::Matrix<Sint32,2,2> Sint32_2_2;

/// 2 x 3 matrix of %Sint32.
///
/// \see #mi::Sint32_2_3_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Sint32 for the type of the matrix components
typedef math::Matrix<Sint32,2,3> Sint32_2_3;

/// 2 x 4 matrix of %Sint32.
///
/// \see #mi::Sint32_2_4_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Sint32 for the type of the matrix components
typedef math::Matrix<Sint32,2,4> Sint32_2_4;

/// 3 x 2 matrix of %Sint32.
///
/// \see #mi::Sint32_3_2_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Sint32 for the type of the matrix components
typedef math::Matrix<Sint32,3,2> Sint32_3_2;

/// 3 x 3 matrix of %Sint32.
///
/// \see #mi::Sint32_3_3_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Sint32 for the type of the matrix components
typedef math::Matrix<Sint32,3,3> Sint32_3_3;

/// 3 x 4 matrix of %Sint32.
///
/// \see #mi::Sint32_3_4_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Sint32 for the type of the matrix components
typedef math::Matrix<Sint32,3,4> Sint32_3_4;

/// 4 x 2 matrix of %Sint32.
///
/// \see #mi::Sint32_4_2_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Sint32 for the type of the matrix components
typedef math::Matrix<Sint32,4,2> Sint32_4_2;

/// 4 x 3 matrix of %Sint32.
///
/// \see #mi::Sint32_4_3_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Sint32 for the type of the matrix components
typedef math::Matrix<Sint32,4,3> Sint32_4_3;

/// 4 x 4 matrix of %Sint32.
///
/// \see #mi::Sint32_4_4_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Sint32 for the type of the matrix components
typedef math::Matrix<Sint32,4,4> Sint32_4_4;



/// 2 x 2 matrix of %Uint32.
///
/// \see #mi::Uint32_2_2_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Uint32 for the type of the matrix components
typedef math::Matrix<Uint32,2,2> Uint32_2_2;

/// 2 x 3 matrix of %Uint32.
///
/// \see #mi::Uint32_2_3_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Uint32 for the type of the matrix components
typedef math::Matrix<Uint32,2,3> Uint32_2_3;

/// 2 x 4 matrix of %Uint32.
///
/// \see #mi::Uint32_2_4_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Uint32 for the type of the matrix components
typedef math::Matrix<Uint32,2,4> Uint32_2_4;

/// 3 x 2 matrix of %Uint32.
///
/// \see #mi::Uint32_3_2_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Uint32 for the type of the matrix components
typedef math::Matrix<Uint32,3,2> Uint32_3_2;

/// 3 x 3 matrix of %Uint32.
///
/// \see #mi::Uint32_3_3_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Uint32 for the type of the matrix components
typedef math::Matrix<Uint32,3,3> Uint32_3_3;

/// 3 x 4 matrix of %Uint32.
///
/// \see #mi::Uint32_3_4_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Uint32 for the type of the matrix components
typedef math::Matrix<Uint32,3,4> Uint32_3_4;

/// 4 x 2 matrix of %Uint32.
///
/// \see #mi::Uint32_4_2_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Uint32 for the type of the matrix components
typedef math::Matrix<Uint32,4,2> Uint32_4_2;

/// 4 x 3 matrix of %Uint32.
///
/// \see #mi::Uint32_4_3_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Uint32 for the type of the matrix components
typedef math::Matrix<Uint32,4,3> Uint32_4_3;

/// 4 x 4 matrix of %Uint32.
///
/// \see #mi::Uint32_4_4_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Uint32 for the type of the matrix components
typedef math::Matrix<Uint32,4,4> Uint32_4_4;



/// 2 x 2 matrix of %Float32.
///
/// \see #mi::Float32_2_2_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Float32 for the type of the matrix components
typedef math::Matrix<Float32,2,2> Float32_2_2;

/// 2 x 3 matrix of %Float32.
///
/// \see #mi::Float32_2_3_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Float32 for the type of the matrix components
typedef math::Matrix<Float32,2,3> Float32_2_3;

/// 2 x 4 matrix of %Float32.
///
/// \see #mi::Float32_2_4_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Float32 for the type of the matrix components
typedef math::Matrix<Float32,2,4> Float32_2_4;

/// 3 x 2 matrix of %Float32.
///
/// \see #mi::Float32_3_2_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Float32 for the type of the matrix components
typedef math::Matrix<Float32,3,2> Float32_3_2;

/// 3 x 3 matrix of %Float32.
///
/// \see #mi::Float32_3_3_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Float32 for the type of the matrix components
typedef math::Matrix<Float32,3,3> Float32_3_3;

/// 3 x 4 matrix of %Float32.
///
/// \see #mi::Float32_3_4_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Float32 for the type of the matrix components
typedef math::Matrix<Float32,3,4> Float32_3_4;

/// 4 x 2 matrix of %Float32.
///
/// \see #mi::Float32_4_2_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Float32 for the type of the matrix components
typedef math::Matrix<Float32,4,2> Float32_4_2;

/// 4 x 3 matrix of %Float32.
///
/// \see #mi::Float32_4_3_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Float32 for the type of the matrix components
typedef math::Matrix<Float32,4,3> Float32_4_3;

/// 4 x 4 matrix of %Float32.
///
/// \see #mi::Float32_4_4_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Float32 for the type of the matrix components
typedef math::Matrix<Float32,4,4> Float32_4_4;



/// 2 x 2 matrix of %Float64.
///
/// \see #mi::Float64_2_2_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Float64 for the type of the matrix components
typedef math::Matrix<Float64,2,2> Float64_2_2;

/// 2 x 3 matrix of %Float64.
///
/// \see #mi::Float64_2_3_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Float64 for the type of the matrix components
typedef math::Matrix<Float64,2,3> Float64_2_3;

/// 2 x 4 matrix of %Float64.
///
/// \see #mi::Float64_2_4_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Float64 for the type of the matrix components
typedef math::Matrix<Float64,2,4> Float64_2_4;

/// 3 x 2 matrix of %Float64.
///
/// \see #mi::Float64_3_2_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Float64 for the type of the matrix components
typedef math::Matrix<Float64,3,2> Float64_3_2;

/// 3 x 3 matrix of %Float64.
///
/// \see #mi::Float64_3_3_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Float64 for the type of the matrix components
typedef math::Matrix<Float64,3,3> Float64_3_3;

/// 3 x 4 matrix of %Float64.
///
/// \see #mi::Float64_3_4_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Float64 for the type of the matrix components
typedef math::Matrix<Float64,3,4> Float64_3_4;

/// 4 x 2 matrix of %Float64.
///
/// \see #mi::Float64_4_2_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Float64 for the type of the matrix components
typedef math::Matrix<Float64,4,2> Float64_4_2;

/// 4 x 3 matrix of %Float64.
///
/// \see #mi::Float64_4_3_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Float64 for the type of the matrix components
typedef math::Matrix<Float64,4,3> Float64_4_3;

/// 4 x 4 matrix of %Float64.
///
/// \see #mi::Float64_4_4_struct for the corresponding POD type,
///      #mi::math::Matrix for the underlying template class, and
///      #mi::Float64 for the type of the matrix components
typedef math::Matrix<Float64,4,4> Float64_4_4;



/// 2 x 2 matrix of bool (underlying POD type).
///
/// \see #mi::Boolean_2_2_struct for the corresponding non-POD type and
///      #mi::math::Matrix_struct for the underlying template class
typedef math::Matrix_struct<bool,2,2> Boolean_2_2_struct;

/// 2 x 3 matrix of bool (underlying POD type).
///
/// \see #mi::Boolean_2_3_struct for the corresponding non-POD type and
///      #mi::math::Matrix_struct for the underlying template class
typedef math::Matrix_struct<bool,2,3> Boolean_2_3_struct;

/// 2 x 4 matrix of bool (underlying POD type).
///
/// \see #mi::Boolean_2_4_struct for the corresponding non-POD type and
///      #mi::math::Matrix_struct for the underlying template class
typedef math::Matrix_struct<bool,2,4> Boolean_2_4_struct;

/// 3 x 2 matrix of bool (underlying POD type).
///
/// \see #mi::Boolean_3_2_struct for the corresponding non-POD type and
///      #mi::math::Matrix_struct for the underlying template class
typedef math::Matrix_struct<bool,3,2> Boolean_3_2_struct;

/// 3 x 3 matrix of bool (underlying POD type).
///
/// \see #mi::Boolean_3_3_struct for the corresponding non-POD type and
///      #mi::math::Matrix_struct for the underlying template class
typedef math::Matrix_struct<bool,3,3> Boolean_3_3_struct;

/// 3 x 4 matrix of bool (underlying POD type).
///
/// \see #mi::Boolean_3_4_struct for the corresponding non-POD type and
///      #mi::math::Matrix_struct for the underlying template class
typedef math::Matrix_struct<bool,3,4> Boolean_3_4_struct;

/// 4 x 2 matrix of bool (underlying POD type).
///
/// \see #mi::Boolean_4_2_struct for the corresponding non-POD type and
///      #mi::math::Matrix_struct for the underlying template class
typedef math::Matrix_struct<bool,4,2> Boolean_4_2_struct;

/// 4 x 3 matrix of bool (underlying POD type).
///
/// \see #mi::Boolean_4_3_struct for the corresponding non-POD type and
///      #mi::math::Matrix_struct for the underlying template class
typedef math::Matrix_struct<bool,4,3> Boolean_4_3_struct;

/// 4 x 4 matrix of bool (underlying POD type).
///
/// \see #mi::Boolean_4_4_struct for the corresponding non-POD type and
///      #mi::math::Matrix_struct for the underlying template class
typedef math::Matrix_struct<bool,4,4> Boolean_4_4_struct;



/// 2 x 2 matrix of %Sint32 (underlying POD type).
///
/// \see #mi::Sint32_2_2_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Sint32 for the type of the matrix components
typedef math::Matrix_struct<Sint32,2,2> Sint32_2_2_struct;

/// 2 x 3 matrix of %Sint32 (underlying POD type).
///
/// \see #mi::Sint32_2_3_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Sint32 for the type of the matrix components
typedef math::Matrix_struct<Sint32,2,3> Sint32_2_3_struct;

/// 2 x 4 matrix of %Sint32 (underlying POD type).
///
/// \see #mi::Sint32_2_4_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Sint32 for the type of the matrix components
typedef math::Matrix_struct<Sint32,2,4> Sint32_2_4_struct;

/// 3 x 2 matrix of %Sint32 (underlying POD type).
///
/// \see #mi::Sint32_3_2_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Sint32 for the type of the matrix components
typedef math::Matrix_struct<Sint32,3,2> Sint32_3_2_struct;

/// 3 x 3 matrix of %Sint32 (underlying POD type).
///
/// \see #mi::Sint32_3_3_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Sint32 for the type of the matrix components
typedef math::Matrix_struct<Sint32,3,3> Sint32_3_3_struct;

/// 3 x 4 matrix of %Sint32 (underlying POD type).
///
/// \see #mi::Sint32_3_4_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Sint32 for the type of the matrix components
typedef math::Matrix_struct<Sint32,3,4> Sint32_3_4_struct;

/// 4 x 2 matrix of %Sint32 (underlying POD type).
///
/// \see #mi::Sint32_4_2_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Sint32 for the type of the matrix components
typedef math::Matrix_struct<Sint32,4,2> Sint32_4_2_struct;

/// 4 x 3 matrix of %Sint32 (underlying POD type).
///
/// \see #mi::Sint32_4_3_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Sint32 for the type of the matrix components
typedef math::Matrix_struct<Sint32,4,3> Sint32_4_3_struct;

/// 4 x 4 matrix of %Sint32 (underlying POD type).
///
/// \see #mi::Sint32_4_4_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Sint32 for the type of the matrix components
typedef math::Matrix_struct<Sint32,4,4> Sint32_4_4_struct;



/// 2 x 2 matrix of %Uint32 (underlying POD type).
///
/// \see #mi::Uint32_2_2_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Uint32 for the type of the matrix components
typedef math::Matrix_struct<Uint32,2,2> Uint32_2_2_struct;

/// 2 x 3 matrix of %Uint32 (underlying POD type).
///
/// \see #mi::Uint32_2_3_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Uint32 for the type of the matrix components
typedef math::Matrix_struct<Uint32,2,3> Uint32_2_3_struct;

/// 2 x 4 matrix of %Uint32 (underlying POD type).
///
/// \see #mi::Uint32_2_4_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Uint32 for the type of the matrix components
typedef math::Matrix_struct<Uint32,2,4> Uint32_2_4_struct;

/// 3 x 2 matrix of %Uint32 (underlying POD type).
///
/// \see #mi::Uint32_3_2_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Uint32 for the type of the matrix components
typedef math::Matrix_struct<Uint32,3,2> Uint32_3_2_struct;

/// 3 x 3 matrix of %Uint32 (underlying POD type).
///
/// \see #mi::Uint32_3_3_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Uint32 for the type of the matrix components
typedef math::Matrix_struct<Uint32,3,3> Uint32_3_3_struct;

/// 3 x 4 matrix of %Uint32 (underlying POD type).
///
/// \see #mi::Uint32_3_4_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Uint32 for the type of the matrix components
typedef math::Matrix_struct<Uint32,3,4> Uint32_3_4_struct;

/// 4 x 2 matrix of %Uint32 (underlying POD type).
///
/// \see #mi::Uint32_4_2_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Uint32 for the type of the matrix components
typedef math::Matrix_struct<Uint32,4,2> Uint32_4_2_struct;

/// 4 x 3 matrix of %Uint32 (underlying POD type).
///
/// \see #mi::Uint32_4_3_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Uint32 for the type of the matrix components
typedef math::Matrix_struct<Uint32,4,3> Uint32_4_3_struct;

/// 4 x 4 matrix of %Uint32 (underlying POD type).
///
/// \see #mi::Uint32_4_4_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Uint32 for the type of the matrix components
typedef math::Matrix_struct<Uint32,4,4> Uint32_4_4_struct;



/// 2 x 2 matrix of %Float32 (underlying POD type).
///
/// \see #mi::Float32_2_2_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Float32 for the type of the matrix components
typedef math::Matrix_struct<Float32,2,2> Float32_2_2_struct;

/// 2 x 3 matrix of %Float32 (underlying POD type).
///
/// \see #mi::Float32_2_3_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Float32 for the type of the matrix components
typedef math::Matrix_struct<Float32,2,3> Float32_2_3_struct;

/// 2 x 4 matrix of %Float32 (underlying POD type).
///
/// \see #mi::Float32_2_4_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Float32 for the type of the matrix components
typedef math::Matrix_struct<Float32,2,4> Float32_2_4_struct;

/// 3 x 2 matrix of %Float32 (underlying POD type).
///
/// \see #mi::Float32_3_2_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Float32 for the type of the matrix components
typedef math::Matrix_struct<Float32,3,2> Float32_3_2_struct;

/// 3 x 3 matrix of %Float32 (underlying POD type).
///
/// \see #mi::Float32_3_3_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Float32 for the type of the matrix components
typedef math::Matrix_struct<Float32,3,3> Float32_3_3_struct;

/// 3 x 4 matrix of %Float32 (underlying POD type).
///
/// \see #mi::Float32_3_4_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Float32 for the type of the matrix components
typedef math::Matrix_struct<Float32,3,4> Float32_3_4_struct;

/// 4 x 2 matrix of %Float32 (underlying POD type).
///
/// \see #mi::Float32_4_2_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Float32 for the type of the matrix components
typedef math::Matrix_struct<Float32,4,2> Float32_4_2_struct;

/// 4 x 3 matrix of %Float32 (underlying POD type).
///
/// \see #mi::Float32_4_3_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Float32 for the type of the matrix components
typedef math::Matrix_struct<Float32,4,3> Float32_4_3_struct;

/// 4 x 4 matrix of %Float32 (underlying POD type).
///
/// \see #mi::Float32_4_4_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Float32 for the type of the matrix components
typedef math::Matrix_struct<Float32,4,4> Float32_4_4_struct;



/// 2 x 2 matrix of %Float64 (underlying POD type).
///
/// \see #mi::Float64_2_2_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Float64 for the type of the matrix components
typedef math::Matrix_struct<Float64,2,2> Float64_2_2_struct;

/// 2 x 3 matrix of %Float64 (underlying POD type).
///
/// \see #mi::Float64_2_3_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Float64 for the type of the matrix components
typedef math::Matrix_struct<Float64,2,3> Float64_2_3_struct;

/// 2 x 4 matrix of %Float64 (underlying POD type).
///
/// \see #mi::Float64_2_4_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Float64 for the type of the matrix components
typedef math::Matrix_struct<Float64,2,4> Float64_2_4_struct;

/// 3 x 2 matrix of %Float64 (underlying POD type).
///
/// \see #mi::Float64_3_2_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Float64 for the type of the matrix components
typedef math::Matrix_struct<Float64,3,2> Float64_3_2_struct;

/// 3 x 3 matrix of %Float64 (underlying POD type).
///
/// \see #mi::Float64_3_3_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Float64 for the type of the matrix components
typedef math::Matrix_struct<Float64,3,3> Float64_3_3_struct;

/// 3 x 4 matrix of %Float64 (underlying POD type).
///
/// \see #mi::Float64_3_4_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Float64 for the type of the matrix components
typedef math::Matrix_struct<Float64,3,4> Float64_3_4_struct;

/// 4 x 2 matrix of %Float64 (underlying POD type).
///
/// \see #mi::Float64_4_2_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Float64 for the type of the matrix components
typedef math::Matrix_struct<Float64,4,2> Float64_4_2_struct;

/// 4 x 3 matrix of %Float64 (underlying POD type).
///
/// \see #mi::Float64_4_3_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Float64 for the type of the matrix components
typedef math::Matrix_struct<Float64,4,3> Float64_4_3_struct;

/// 4 x 4 matrix of %Float64 (underlying POD type).
///
/// \see #mi::Float64_4_4_struct for the corresponding non-POD type,
///      #mi::math::Matrix_struct for the underlying template class, and
///      #mi::Float64 for the type of the matrix components
typedef math::Matrix_struct<Float64,4,4> Float64_4_4_struct;

/**@}*/ // end group mi_neuray_compounds

} // namespace mi

#endif // MI_NEURAYLIB_MATRIX_TYPEDEFS_H
