# SmartAsserts

## Description

A plugin for Unreal Engine 5 that adds asserts that crashes the PIE session instead of the entire editor.

This is done by immediately causing a blueprint breakpoint and then exiting the PIE session.
All smart asserts log their messages both to the logger and to the PIE message window. This is the same place where blueprint runtime errors get logged. Default settings have this window automatically pop up after exiting a PIE session where an error occurred. This was purposefully designed so blueprint programmers and designers would notice the errors if they wouldn't normally look in the log.

## Requirement

Target version : UE 5.1-5.5    
Target platform : Windows  

## Installation

### From the [Fab marketplace](https://www.fab.com/listings/fbe2cfc8-c483-4c9b-a2ab-5d9090b1d6a4):

Installing SmartAsserts from the Fab marketplace will install it to Unreal Engine instead of a specifc project. To be able to use it in a project, you need to install this plugin to the Unreal Engine version the project is built in. Then, in the project, you need to enable it by going to the Plugins window (Edit->Plugins), then checking the box to the left of the icon on the Smart Asserts plugin (which should be under Installed->Programming). 
If you wish to enable to the plugin manually, add this to your .uproject file:
```
"Plugins": [
  {
    "Name": "SafeCheck",
    "Enabled": true,
    "MarketplaceURL": "https://www.fab.com/listings/77a7b694-c15e-4e7f-a15d-bef5d82ae70d"
  }
]
```
If you want the plugin installed to a specific project and not an engine, follow these instructions instead. Install the plugin to the engine matching the project you want it added. Copy the files downloaded into ``Unreal Engine version location->Engine->Plugins->Marketplace->SmartAsserts`` (There might be a long line of random characters after SmartAsserts) then paste them into ``Project Folder->Plugins->SmartAsserts``. You are then able to uninstall the plugin from the engine.

### From [GitHub](https://github.com/jjasundry/SmartAsserts)

Download the files from the branch named after the version of Unreal your project is built in. Place the files in this path: ``Project Folder->Plugins->SmartAsserts``. You will need to rebuild the plugin from source. 

### Using this Plugin

After installing the plugin, you should be able to call all blueprint nodes in the editor. I'd recommend making sure the "Assert" node shows up. If it does not, the plugin did not get installed.
To access the C++ features of this plugin, add ``"SafeCheckMacros"`` to the PrivateDependencyModuleNames in the .Build.cs file of the module you want to use this plugin. After that, you are able to add ``#include "SafeCheckMacros.h"`` to any file inside that module and access all of the C++ features from this module.

## Features And Usages

### C++

Adds several macros similiar to Unreal's assertion macros, like [check](https://dev.epicgames.com/documentation/en-us/unreal-engine/asserts-in-unreal-engine).
If these macros detect the function wasn't called from Blueprint, it will function like a normal assertion, crashing the entire editor. Otherwise, _all_ C++ code will complete in the current stack until control is returned to Blueprint, where the editor will stop the PIE session. This means all smart assert macros need to return, or the code after them will still execute, which is a big problem! If a blueprint node calls C++ function 1, which calls function 2, and function 2 asserts, function 1 will still fully execute. If function 1 also asserts, 2 assert messages will appear in the logs.

| **Name**                          | **Macro**                                       | **Description**                                                      |
|-----------------------------------|-------------------------------------------------|----------------------------------------------------------------------|
| Safe Check                        | scheck(expression)                              | Crashes the play session. Becomes check outside the editor. Will output an error message to the logs. Returns void. |
| Safe Check with message           | scheckf(expression, format, ...)                | Crashes the play session. Becomes checkf outside the editor. Will output an error message with the user's formatted message to the logs. Returns void. |
| Safe Check returning              | srcheck(expression, return_value)               | Crashes the play session. Becomes check outside the editor. Will output an error message to the logs. Returns the provided value. |
| Safe Check returning with message | srcheckf(expression, return_value, format, ...) | Crashes the play session. Becomes checkf outside the editor. Will output an error message with the user's formatted message to the logs. Returns the provided value. |

### Blueprint

Adds a node called "Assert" that will crash the PIE session. Outside the editor or PIE session, this node will call check. The node takes an optional message parameter for the user to specify in the log. If left empty, the node will log a generic error. The log will always include a link to the specific node that logged it, allowing users to quickly navigate to the code that had the error.

## License

[Creative Commons Attribution (CC BY 4.0)](https://creativecommons.org/licenses/by/4.0/)

## Author

[Adam White](https://arwtsh.wixsite.com/portfolio)

## History

- (1/8/2025) v1.0  
  Published to GitHub and Fab marketplace 
