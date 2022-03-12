add_requires('vcpkg::wxwidgets', {alias='wx',system=true})
add_requires('vcpkg::libpng', {alias='libpng',system=true})
add_requires('vcpkg::zlib', {alias='zlib',system=true})

target('lua')
  set_kind('static')
  add_includedirs('lua')
  add_files('lua/*.c')

target('gui-calc')
  set_kind('binary')
  add_files('form/calcui.cpp')
  add_files('main.cpp')
  add_packages('wx','libpng','zlib')
  add_includedirs('lua')
  add_deps('lua')
  if is_plat('windows') then
    add_links('uuid','gdi32','comdlg32','comctl32','ws2_32','user32','winspool','ole32','rpcrt4','advapi32','shell32')
  end
  --add_defines('UNICODE','_UNICODE','NDEBUG','wxMONOLITHIC=1','wxNO_GL_LIB=1')

  --if is_plat('windows') then
  --  add_includedirs('$(wxdir)/include/msvc')
  --  --add_includedirs('$(wxdir/vc_x64_lib/mswu')
  --end
  --add_includedirs('$(wxdir)/include')
  --add_linkdirs('$(wxdir)/lib/vc_x64_lib')
  --add_deps('quickjs')
  --add_links('wxexpat', 'wxjpeg', 'wxmsw31u', 'wxpng', 'wxregexu', 'wxscintilla', 'wxtiff', 'wxzlib')

