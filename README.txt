Documentation: https://github.com/jjasundry/SmartAsserts/blob/main/README.md

A plugin for Unreal Engine 5 that adds asserts that crashes the PIE session instead of the entire editor.

This is done by immediately causing a blueprint breakpoint and then exiting the PIE session. All smart asserts log their messages both to the logger, but also to the PIE message window. This is the same place where blueprint runtime errors get logged to. Default settings have this window automatically pop up after exiting a PIE session where an error occurred. This was purposefully designed so blueprint programmers and designers would notice the errors, when they wouldn't normally look in the log.
