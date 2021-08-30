SUMMARY = "Dreambox EGL and GLES2 libraries"
LICENSE = "CLOSED"
DEPENDS = "${LIBEGLDEP}"
PROVIDES = "virtual/egl virtual/libgles1 virtual/libgles2"
RPROVIDES_${PN} = "virtual/egl virtual/libgles1 virtual/libgles2"

LIBEGLDEP = ""
LIBEGLDEP_dm520 = "libv3ddriver"
LIBEGLDEP_dm820 = "libv3ddriver"
LIBEGLDEP_dm7080 = "libv3ddriver"
LIBEGLDEP_dm900 = "libvc5driver"
LIBEGLDEP_dm920 = "libvc5driver"

LIBEGLRDEP = ""
LIBEGLRDEP_dm820 = "libv3ddriver"
LIBEGLRDEP_dm7080 = "libv3ddriver"
LIBEGLRDEP_dm900 = "libvc5driver"
LIBEGLRDEP_dm920 = "libvc5driver"

RDEPENDS_${PN} = "${LIBEGLRDEP}"

RPROVIDES_${PN} = "libegl libegl1 libgles1 libgles2 libglesv2-2"
RPROVIDES_${PN}-dev = "libegl-dev libgles1-dev libgles2-dev"

RCONFLICTS_${PN} = "libegl libegl1 libgles1 libgles2 libglesv2-2"
RCONFLICTS_${PN}-dev = "libegl-dev libgles1-dev libgles2-dev"

RREPLACES_${PN} = "libegl libegl1 libgles1 libgles2 libglesv2-2"
RREPLACES_${PN}-dev = "libegl-dev libgles1-dev libgles2-dev"

# As a workaround, keep .so symlinks in base package
# until all users were recompiled.
FILES_${PN} += "${libdir}/lib*${SOLIBSDEV}"
FILES_SOLIBSDEV = ""
INSANE_SKIP_${PN} += "already-stripped dev-so ldflags"
