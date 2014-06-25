/*
 * Game Develop C++ Platform
 * Copyright 2008-2014 Florian Rival (Florian.Rival@gmail.com). All rights reserved.
 * This project is released under the GNU Lesser General Public License.
 */
#if defined(GD_IDE_ONLY)

#ifndef PROFILETOOLS_H
#define PROFILETOOLS_H
#include <vector>
#include <map>
class ProfileEvent;
namespace gd { class Layout; }
class RuntimeScene;

void GD_API StartProfileTimer(RuntimeScene & scene, unsigned int id);
void GD_API EndProfileTimer(RuntimeScene & scene, unsigned int id);

#endif // PROFILETOOLS_H

#endif