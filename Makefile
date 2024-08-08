# $FreeBSD$

PORTNAME=pfSense-pkg-wstunnel
PORTVERSION=9.2.3
PORTREVISION=3
CATEGORIES=security
MASTER_SITES=
DISTFILES=
EXTRACT_ONLY=

MAINTAINER=grimsteel.MGdpdGh1Yg@kameswar.com
COMMENT=Unofficial pfSense wstunnel package
LICENSE=BSD3CLAUSE
RUN_DEPENDS=${LOCALBASE}/bin/wstunnel:${PORTSDIR}/net/wstunnel

NO_BUILD=yes
NO_MTREE=yes

SUB_FILES=pkg-install pkg-deinstall
SUB_LIST=PORTNAME=${PORTNAME}

do-extract:
	${MKDIR} ${WRKSRC}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/pkg
	${MKDIR} ${STAGEDIR}/etc/inc/priv
	${MKDIR} ${STAGEDIR}${PREFIX}/www/shortcuts
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} -m 0644 ${FILESDIR}${PREFIX}/pkg/wstunnel.xml \
		${STAGEDIR}${PREFIX}/pkg
	${INSTALL_DATA} ${FILESDIR}${PREFIX}/pkg/wstunnel.inc \
		${STAGEDIR}${PREFIX}/pkg
	${INSTALL_DATA} ${FILESDIR}/etc/inc/priv/wstunnel.priv.inc \
		${STAGEDIR}/etc/inc/priv
	${INSTALL_DATA} ${FILESDIR}${PREFIX}/www/shortcuts/pkg_wstunnel.inc \
		${STAGEDIR}${PREFIX}/www/shortcuts
	${INSTALL_DATA} ${FILESDIR}${DATADIR}/info.xml \
		${STAGEDIR}${DATADIR}
	@${REINPLACE_CMD} -i '' -e "s|%%PKGVERSION%%|${PKGVERSION}|" \
		${STAGEDIR}${DATADIR}/info.xml \
		${STAGEDIR}${PREFIX}/pkg/wstunnel.xml

.include <bsd.port.mk>
