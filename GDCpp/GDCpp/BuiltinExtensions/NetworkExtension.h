/*
 * Game Develop C++ Platform
 * Copyright 2008-2014 Florian Rival (Florian.Rival@gmail.com). All rights reserved.
 * This project is released under the GNU Lesser General Public License.
 */

#ifndef NETWORKEXTENSION_H
#define NETWORKEXTENSION_H

#include "GDCpp/ExtensionBase.h"

/**
 * \brief Internal built-in extension providing very basic network features.
 *
 * \ingroup BuiltinExtensions
 */
class NetworkExtension : public ExtensionBase
{
    public:
        NetworkExtension();
        virtual ~NetworkExtension() {};
    protected:
    private:
};

#endif // NETWORKEXTENSION_H

