if is_plat('windows') then
  add_requires('vcpkg::wxwidgets', {alias='wx',system=true})
  add_requires('vcpkg::libpng', {alias='libpng',system=true})
  add_requires('vcpkg::zlib', {alias='zlib',system=true})
end

target('lua')
  set_kind('static')
  add_includedirs('lua')
  add_files('lua/*.c')

target('iiic')
  set_kind('binary')
  set_optimize('minimal')
  add_files('form/ui.cpp')
  add_files('main.cpp')
  add_includedirs('lua')
  add_deps('lua')
  if is_plat('windows') then
    add_files('iiic.rc')
    add_rules("win.sdk.application")
    add_packages('wx','libpng','zlib')
    add_cxflags('/bigobj')
    add_links('uuid','gdi32','comdlg32','comctl32','ws2_32','user32','winspool','ole32','rpcrt4','advapi32','shell32')
  elseif is_plat('linux') then
    add_defines('__WXGTK__')
    add_includedirs('/usr/include/wx-3.0')
    add_includedirs('/usr/lib64/wx/include/gtk3-unicode-3.0')
    add_links('wx_gtk3u_core-3.0','wx_gtk3u_adv-3.0','wx_baseu-3.0','png','z')
  elseif is_plat('msys') or is_subhost('msys') then
    add_ldflags('-static')
    add_ldflags('-Wl,--subsystem,windows')
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

