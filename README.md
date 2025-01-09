# SmartAsserts

## Description

A plugin for Unreal Engine 5 that adds asserts that crashes the PIE session instead of the entire editor.

This is done by immediately causing a blueprint breakpoint and then exiting the PIE session.
All smart asserts log their messages both to the logger, but also to the PIE message window. This is the same place where blueprint runtime errors get logged to. Default settings have this window automatically pop up after exiting a PIE session where an error occurred. This was purposefully designed so blueprint programmers and designers would notice the errors, when they wouldn't normally look in the log.

## Requirement

Target version : UE 5.0-5.5    
Target platform : Windows  

## Installation

You can access the plugin either from the [GitHub repo](https://github.com/jjasundry/SmartAsserts), or from the [Fab marketplace](https://www.fab.com).

The main branch of the repo contains the raw source of the plugin. If you have a C++ project, you can add the plugin to your project manually and recompile.
If your project is in an Unreal version of one of the other branch's names, then you can instal the plugin from that branch without having to recompile your project.

## Features And Usages

**C++**

Adds several macros similiar to Unreal's assertion macros, like _check_.
If these macros detect the function wasn't called from Blueprint, it will function like a normal assertion, crashing the entire editor. Otherwise, _all_ C++ code will complete in the current stack until control is returned to Blueprint, where the editor will stop the PIE session. This means all smart assert macros need to return, or the code after them will still execute, which is a big problem! If a blueprint node calls C++ function 1, which calls function 2, and function 2 asserts, function 1 will still fully execute. If function 1 also asserts, 2 assert messages will appear in the logs.

| **Name**                          | **Macro**                                       | **Description**                                                      |
|-----------------------------------|-------------------------------------------------|----------------------------------------------------------------------|
| Safe Check                        | scheck(expression)                              | Crashes the play session. Becomes check outside the editor. Will output an error message to the logs. Returns void. |
| Safe Check with message           | scheckf(expression, format, ...)                | Crashes the play session. Becomes checkf outside the editor. Will output an error message with the user's formatted message to the logs. Returns void. |
| Safe Check returning              | srcheck(expression, return_value)               | Crashes the play session. Becomes check outside the editor. Will output an error message to the logs. Returns the provided value. |
| Safe Check returning with message | srcheckf(expression, return_value, format, ...) | Crashes the play session. Becomes checkf outside the editor. Will output an error message with the user's formatted message to the logs. Returns the provided value. |

**Blueprint**

Adds a node called "Assert" that will crash the PIE session. Outside the editor or PIE session, this node will call check. The node takes an optional message parameter for the user to specify in the log. If left empty, the node will log a generic error. The log will always include a link to the specific node that logged it, allowing users to quickly navigate to the code that had the error.

## License

[Creative Commons Attribution (CC BY 4.0)](https://creativecommons.org/licenses/by/4.0/)

## Author

[Adam White](https://arwtsh.wixsite.com/portfolio)

## History

- (1/8/2025) v1.0  
  Published to github and Fab marketplace 
