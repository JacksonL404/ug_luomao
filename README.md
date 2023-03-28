# ug_luomao

This is an example program for using the Unigraphics (UG) Open API to create various geometric features in a CAD model. The program includes several functions for creating different types of features, such as cones, cylinders, and blocks, using the UF_MODL module.

The do_ugopen_api() function is the main function of the program and calls other functions to create the different features. It creates a cone and a cylinder, which are subtracted from each other to create a cavity. It also creates a block and a circular iset, which are added together to form a cutout in the block.

The code uses various data types and functions provided by the UG Open API, such as tag_t for object IDs and UF_MODL functions for creating and manipulating objects. The UF_CALL macro is used to check for errors and report them if they occur.
