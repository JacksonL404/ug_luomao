# ug_luomao

This is an example program for using the Unigraphics (UG) Open API to create various geometric features in a CAD model. The program includes several functions for creating different types of features, such as cones, cylinders, and blocks, using the UF_MODL module.The program ultimately creates a variant hexagonal-headed nut.

这是一个示例程序，用于使用 Unigraphics (UG) Open API 在 CAD 模型中创建各种几何特征。该程序包括多个函数，用于使用 UF_MODL 模块创建不同类型的特征，例如圆锥体、圆柱体和块体。该程序最终创建了一个变体六角螺母。

The do_ugopen_api() function is the main function of the program and calls other functions to create the different features. It creates a cone and a cylinder, which are subtracted from each other to create a cavity. It also creates a block and a circular iset, which are added together to form a cutout in the block.

do_ugopen_api() 函数是程序的主要函数，它调用其他函数来创建不同的功能。它创建了一个圆锥体和一个圆柱体，它们相互减去以创建一个空腔。它还会创建一个块和一个圆形 iset，将它们加在一起以在块中形成一个切口。

The code uses various data types and functions provided by the UG Open API, such as tag_t for object IDs and UF_MODL functions for creating and manipulating objects. The UF_CALL macro is used to check for errors and report them if they occur.

该代码使用了 UG Open API 提供的各种数据类型和函数，例如用于对象 ID 的 tag_t 和用于创建和操作对象的 UF_MODL 函数。 UF_CALL 宏用于检查错误并在错误发生时报告错误。
