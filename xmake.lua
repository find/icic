option('wxdir')
  set_default('')
  set_showmenu(true)

--target('quickjs')
--  set_kind('static')
--  add_files('quickjs/*.c')

target('qjscalc_ui')
  set_kind('binary')
  add_files('form/qjscalc_ui.cpp')
  add_files('main.cpp')
  add_defines('UNICODE','_UNICODE','NDEBUG','wxMONOLITHIC=1','wxNO_GL_LIB=1')

  if is_plat('windows') then
    add_includedirs('$(wxdir)/include/msvc')
    --add_includedirs('$(wxdir/vc_x64_lib/mswu')
  end
  add_includedirs('$(wxdir)/include')
  add_linkdirs('$(wxdir)/lib/vc_x64_lib')
  --add_deps('quickjs')
  --add_links('wxexpat', 'wxjpeg', 'wxmsw31u', 'wxpng', 'wxregexu', 'wxscintilla', 'wxtiff', 'wxzlib')

