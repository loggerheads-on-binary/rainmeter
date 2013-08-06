/*
  Copyright (C) 2010 Matt King, Birunthan Mohanathas

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful, 
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef __LUAMANAGER_H__
#define __LUAMANAGER_H__

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

class LuaManager
{
public:
	static void Initialize();
	static void Finalize();

	static lua_State* GetState(bool unicode) { c_UnicodeState = unicode; return c_State; }

	static bool IsUnicodeState() { return c_UnicodeState; }

	static void ReportErrors(const std::wstring& file);

	static void PushWide(const WCHAR* str);
	static void PushWide(const std::wstring& str);
	static std::wstring ToWide(int narg);

protected:
	static int c_RefCount;
	static lua_State* c_State;

private:
	static void RegisterGlobal(lua_State* L);
	static void RegisterMeasure(lua_State* L);
	static void RegisterMeter(lua_State* L);
	static void RegisterMeterWindow(lua_State* L);
	static void RegisterMeterString(lua_State* L);

	// If set true |true|, Lua strings converted to/from as if they were encoded in UTF-8. Otherwise
	// Lua strings are treated as if they are encoded in the default system encoding.
	static bool c_UnicodeState;
};

#endif
