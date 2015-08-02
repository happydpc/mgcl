# Getting Started #

In this chapter, you will learn to make a simple console application using MGCL.
Note that this article is written with Microsoft Visual Studio .NET 2003 (msvc71).



## Download Prebuilt MGCL ##

From [Downloads](http://code.google.com/p/mgcl/downloads/list) page, get

  * pre-built MGCL package and
  * sample project

then unzip both files.

## Configure Visual Studio Settings ##

Althouth the description below is how to configure IDE settings of msvc71,
you may apply the same way to newer versions of msvc as well.

First you need to add an include path and a library path to IDE.

![http://mgcl.googlecode.com/svn/wiki/image/settings-path.png](http://mgcl.googlecode.com/svn/wiki/image/settings-path.png)

## Build the Sample Project ##
**Download files are now unavailable.**  Please wait for a while.

## Set Configuration Properties ##

When you develop an application using MGCL but not MFC,
configure project properties like as follows:

  * General
    * Use of MFC: **Use Standard Windows Libraries**
    * Character Set: **Multibyte Character Set**
  * C/C++
    * Preprocessor
      * Preprocessor definitions: Add **MGCL\_NO\_MFC**.
    * Code Generation
      * Runtime Library: **/MD** (Release) or **/MDd** (Debug).
  * Linker
    * Input: Add **mgcl-nomfc.lib** (Release) or **mgcl-nomfcd.lib** (Debug).

When you develop applications using both MGCL and MFC, configure project properties as below:

  * General
    * Use of MFC: **Use MFC in a Shared Library**
    * Character Set: **Multibyte Character Set**
  * C/C++
    * Code Generation
      * Runtime Library: **/MD** (Release) or **/MDd** (Debug).
  * Linker
    * Input: Add **mgcl-nomfc.lib** (Release) or **mgcl-nomfcd.lib** (Debug).
> > > Additionally add **opengl32.lib** and **gdiplus.lib**.