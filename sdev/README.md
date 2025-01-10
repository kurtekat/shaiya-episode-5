## Environment

Windows 10

Visual Studio 2022

C++ 23

## Prerequisites

[Microsoft Visual C++ Redistributable](https://aka.ms/vs/17/release/vc_redist.x86.exe)

## Binaries

https://github.com/kurtekat/shaiya-episode-5/tree/main/sdev/bin/

# Features

This library provides bare minimum support for the item mall and exchange confirmation.

## Item Mall

Install the following procedures:

```
[dbo].[usp_Read_User_CashPoint_UsersMaster]
[dbo].[usp_Save_User_BuyPointItems2]
[dbo].[usp_Save_User_GiftPointItems2]
[dbo].[usp_Update_UserPoint]
```

If you receive an error, change `ALTER` to `CREATE` and try again.
