/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2014 Richard Hughes <richard@hughsie.com>
 *
 * Licensed under the GNU Lesser General Public License Version 2.1
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 */

#if !defined (__APPSTREAM_GLIB_H) && !defined (AS_COMPILATION)
#error "Only <appstream-glib.h> can be included directly."
#endif

#ifndef AS_APP_H
#define AS_APP_H

#include <glib-object.h>

#include "as-release.h"
#include "as-screenshot.h"

#define AS_TYPE_APP		(as_app_get_type())
#define AS_APP(obj)		(G_TYPE_CHECK_INSTANCE_CAST((obj), AS_TYPE_APP, AsApp))
#define AS_APP_CLASS(cls)	(G_TYPE_CHECK_CLASS_CAST((cls), AS_TYPE_APP, AsAppClass))
#define AS_IS_APP(obj)		(G_TYPE_CHECK_INSTANCE_TYPE((obj), AS_TYPE_APP))
#define AS_IS_APP_CLASS(cls)	(G_TYPE_CHECK_CLASS_TYPE((cls), AS_TYPE_APP))
#define AS_APP_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS((obj), AS_TYPE_APP, AsAppClass))

G_BEGIN_DECLS

typedef struct _AsApp		AsApp;
typedef struct _AsAppClass	AsAppClass;

struct _AsApp
{
	GObject			parent;
};

struct _AsAppClass
{
	GObjectClass		parent_class;
};

typedef enum {
	AS_APP_ICON_KIND_UNKNOWN,
	AS_APP_ICON_KIND_STOCK,
	AS_APP_ICON_KIND_CACHED,
	AS_APP_ICON_KIND_REMOTE,
	AS_APP_ICON_KIND_LAST
} AsAppIconKind;

typedef enum {
	AS_APP_ID_KIND_UNKNOWN,
	AS_APP_ID_KIND_DESKTOP,
	AS_APP_ID_KIND_FONT,
	AS_APP_ID_KIND_CODEC,
	AS_APP_ID_KIND_INPUT_METHOD,
	AS_APP_ID_KIND_WEB_APP,
	AS_APP_ID_KIND_SOURCE,
	AS_APP_ID_KIND_LAST
} AsAppIdKind;

GType		 as_app_get_type		(void);
AsApp		*as_app_new			(void);

/* helpers */
const gchar	*as_app_id_kind_to_string	(AsAppIdKind	 kind);
AsAppIdKind	 as_app_id_kind_from_string	(const gchar	*kind);
const gchar	*as_app_icon_kind_to_string	(AsAppIconKind	 icon_type);
AsAppIconKind	 as_app_icon_kind_from_string	(const gchar	*icon_type);

/* getters */
AsAppIdKind	 as_app_get_id_kind		(AsApp		*app);
GList		*as_app_get_languages		(AsApp		*app);
GPtrArray	*as_app_get_categories		(AsApp		*app);
GPtrArray	*as_app_get_keywords		(AsApp		*app);
GPtrArray	*as_app_get_pkgnames		(AsApp		*app);
GPtrArray	*as_app_get_releases		(AsApp		*app);
GPtrArray	*as_app_get_screenshots		(AsApp		*app);
GHashTable	*as_app_get_urls		(AsApp		*app);
const gchar	*as_app_get_icon		(AsApp		*app);
const gchar	*as_app_get_id			(AsApp		*app);
const gchar	*as_app_get_id_full		(AsApp		*app);
const gchar	*as_app_get_project_group	(AsApp		*app);
const gchar	*as_app_get_name		(AsApp		*app,
						 const gchar	*locale);
const gchar	*as_app_get_comment		(AsApp		*app,
						 const gchar	*locale);
const gchar	*as_app_get_language		(AsApp		*app,
						 const gchar	*locale);
const gchar	*as_app_get_metadata_item	(AsApp		*app,
						 const gchar	*key);
const gchar	*as_app_get_url_item		(AsApp		*app,
						 const gchar	*type);

/* setters */
void		 as_app_set_id_full		(AsApp		*app,
						 const gchar	*id_full);
void		 as_app_set_id_kind		(AsApp		*app,
						 AsAppIdKind	 kind);
void		 as_app_set_project_group	(AsApp		*app,
						 const gchar	*project_group);
void		 as_app_set_project_license	(AsApp		*app,
						 const gchar	*project_license);
void		 as_app_set_icon		(AsApp		*app,
						 const gchar	*icon);
void		 as_app_set_icon_kind		(AsApp		*app,
						 AsAppIconKind	 icon_type);
void		 as_app_set_name		(AsApp		*app,
						 const gchar	*locale,
						 const gchar	*name);
void		 as_app_set_comment		(AsApp		*app,
						 const gchar	*locale,
						 const gchar	*comment);
void		 as_app_set_description		(AsApp		*app,
						 const gchar	*locale,
						 const gchar	*description);
void		 as_app_add_category		(AsApp		*app,
						 const gchar	*category);
void		 as_app_add_keyword		(AsApp		*app,
						 const gchar	*keyword);
void		 as_app_add_mimetype		(AsApp		*app,
						 const gchar	*mimetype);
void		 as_app_add_pkgname		(AsApp		*app,
						 const gchar	*pkgname);
void		 as_app_add_release		(AsApp		*app,
						 AsRelease	*release);
void		 as_app_add_screenshot		(AsApp		*app,
						 AsScreenshot	*screenshot);
void		 as_app_add_language		(AsApp		*app,
						 const gchar	*locale,
						 const gchar	*value);
void		 as_app_add_compulsory_for_desktop (AsApp	*app,
						 const gchar	*compulsory_for_desktop);
void		 as_app_add_url			(AsApp		*app,
						 const gchar	*type,
						 const gchar	*url);
void		 as_app_add_metadata		(AsApp		*app,
						 const gchar	*key,
						 const gchar	*value);
void		 as_app_remove_metadata		(AsApp		*app,
						 const gchar	*key);

/* object methods */
void		 as_app_subsume			(AsApp		*app,
						 AsApp		*donor);

G_END_DECLS

#endif /* AS_APP_H */