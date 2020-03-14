# Properties, schemas and PropertiesEditor explanations

## The need for a concept of "properties"

A lot of elements in GDevelop can have fields which can be edited by the user. For example:
* a behavior has properties that are, for most behaviors, strings, numbers and booleans.
* an object also has properties that are shown in the editor. They are often strings (the text to display in a text object), numbers (the number of particles), booleans (a checkbox to set if a text is displayed in bold or not) and also sometimes can be a resource (for example, the image to be displayed by a tiled sprite object or the font to be used by a text object).
* an instance on a scene also has a bunch of properties: its X and Y coordinates, its angle, etc...

While some object or behaviors can have their own editor, with a custom interface written in React (find them in [`newIDE/app/src/ObjectEditor/Editors`](https://github.com/4ian/GDevelop/tree/master/newIDE/app/src/ObjectEditor/Editors) for objects and in [`newIDE/app/src/BehaviorsEditor/Editors`](https://github.com/4ian/GDevelop/tree/master/newIDE/app/src/BehaviorsEditor/Editors) for behaviors), the large majority of object/behavior editors can be automatically generated by looking at the properties of the said objects/behaviors, and creating a field for them.

That's why object and behaviors can have "properties". A property is defined by a [class in GDCore called PropertyDescriptor](https://github.com/4ian/GDevelop/blob/master/Core/GDCore/Project/PropertyDescriptor.h).

## How to declare these properties?

* You can use them when declaring **an object or behavior** in JavaScript (in `JsExtension.js`). For example, in the case of a Video Object:

    ```js
        videoObject.getProperties = function(objectContent) {
        var objectProperties = new gd.MapStringPropertyDescriptor();
        objectProperties.set(
            "Opacity",
            new gd.PropertyDescriptor(objectContent.opacity.toString())
            .setType("number")
            .setLabel(_("Video opacity (0-255)"))
        );
        objectProperties.set(
            "Looped",
            new gd.PropertyDescriptor(objectContent.loop ? "true" : "false")
            .setType("boolean")
            .setLabel(_("Loop the video"))
        );
        objectProperties.set(
            "videoResource",
            new gd.PropertyDescriptor(objectContent.videoResource)
            .setType("resource")
            .addExtraInfo("video")
            .setLabel(_("Video resource"))
        );

        return objectProperties;
        };
    ```

* Their usage is mostly the same in C++. For example, in the case of a Skeleton Object:

    ```c++
    std::map<gd::String, gd::PropertyDescriptor> SkeletonObject::GetProperties(
        gd::Project& project) const {
    std::map<gd::String, gd::PropertyDescriptor> properties;
    properties[_("Skeletal data filename")].SetValue(skeletalDataFilename)
        .SetType("resource").AddExtraInfo("json");
    properties[_("Main armature name")].SetValue(rootArmatureName);
    properties[_("Texture data filename")].SetValue(textureDataFilename)
        .SetType("resource").AddExtraInfo("json");
    properties[_("Texture")].SetValue(textureName)
        .SetType("resource").AddExtraInfo("image");

    return properties;
    }
    ```
* **Behaviors** can also have properties (check example of existing behaviors in `JsExtension.js` or in C++ behaviors)
* **Instances** of objects can also have custom properties.

> Declaring properties is not enough, for behaviors, objects and instances you also need to implement `updateProperty` in JS (or `UpdateProperty` in C++), that will be called to update a property when the user changes it in the editor. Use this method to add any validation if needed.

## What "types" of properties are supported?

The `PropertyDescriptor` has a `setType` (or `SetType` in C++) method. You can call it with:

* `"string"` to get a string input field (this is the default),
* `"number"` to get a number input field,
* `"boolean"` to get a checkbox
* `"resource"` to get a resource selector. The resource will be stored as a string, but the editor will show a selector allowing to choose a resource, that will be added to the project.
  * In this case, you also need to call `addExtraInfo` (`AddExtraInfo` in C++) with the type of the resource: `"image"`, `"audio"`, `"font"` or `"json"`.

## Where can I find their source code?

* [PropertyDescriptor](https://github.com/4ian/GDevelop/blob/master/Core/GDCore/Project/PropertyDescriptor.h)
* A PropertyDescriptor is mapped to [a schema](https://github.com/4ian/GDevelop/blob/bc80d1c98f22bb8aae559b1fbcb25452d9a6b9d8/newIDE/app/src/PropertiesEditor/PropertiesMapToSchema.js#L109-L124) that is then displayed by [PropertiesEditor](https://github.com/4ian/GDevelop/blob/bc80d1c98f22bb8aae559b1fbcb25452d9a6b9d8/newIDE/app/src/PropertiesEditor/index.js#L314).
* A "schema" describes what a PropertiesEditor will display on screen. It's somewhat similar to PropertyDescriptor. The two concepts should be merged at some point.