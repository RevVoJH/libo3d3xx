// -*- c++ -*-
/*
 * Copyright (C) 2014 Love Park Robotics, LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distribted on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __O3D3XX_VERSION_H__
#define __O3D3XX_VERSION_H__

#define O3D3XX_LIBRARY_NAME "libo3d3xx"

/* compile-time API version detection */
/* variable expansion comes from CMakeLists.txt -- don't mess with these */
//#define O3D3XX_VERSION_MAJOR @O3D3XX_VERSION_MAJOR@
//#define O3D3XX_VERSION_MINOR @O3D3XX_VERSION_MINOR@
//#define O3D3XX_VERSION_PATCH @O3D3XX_VERSION_PATCH@

#define O3D3XX_VERSION_MAJOR 0
#define O3D3XX_VERSION_MINOR 7
#define O3D3XX_VERSION_PATCH 5

#define O3D3XX_MAKE_VERSION(major, minor, patch) \
  ((major) * 10000 + (minor) * 100 + (patch))
#define O3D3XX_VERSION \
  O3D3XX_MAKE_VERSION( \
        O3D3XX_VERSION_MAJOR, \
        O3D3XX_VERSION_MINOR, \
        O3D3XX_VERSION_PATCH)

namespace o3d3xx
{
  /**
   * @brief Runtime API version detection
   *
   * @param[out] major Major version number
   * @param[out] minor Minor version number
   * @param[out] patch Patch version number
   */
  void version(int *major, int *minor, int *patch);

} // end: namespace o3d3xx

#endif // __O3D3XX_VERSION_H__
