#pragma once
#ifndef __BASE_TYPE_H__
#define __BASE_TYPE_H__

#if defined(WIN32) && defined(DLL_EXPORTS)
#define DLL_EXPORT __declspec(dllexport)
//#define DLL_EXPORT_TEMPLATE

#elif defined(WIN32) && defined(NDEBUG)
#define DLL_EXPORT __declspec(dllimport)
//#define DLL_EXPORT_TEMPLATE extern

//extern "C" __declspec(DLL_EXPORT) 

#else
#define DLL_EXPORT

#endif // !__BASE_TYPE_H__

#define DLL_VER "ver 0.2.0"

#endif
