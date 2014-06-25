/*
 * Game Develop C++ Platform
 * Copyright 2008-2014 Florian Rival (Florian.Rival@gmail.com). All rights reserved.
 * This project is released under the GNU Lesser General Public License.
 */

#ifndef SPRITEEXTENSION_H
#define SPRITEEXTENSION_H
#include "GDCpp/ExtensionBase.h"

/**
 * \brief Internal built-in extension providing SpriteObject objects.
 *
 *
 * \ingroup BuiltinExtensions
 * \ingroup SpriteObjectExtension
 */
class SpriteExtension : public ExtensionBase
{
    public :

    SpriteExtension();
    virtual ~SpriteExtension() {};
};

#endif // SPRITEEXTENSION_H

