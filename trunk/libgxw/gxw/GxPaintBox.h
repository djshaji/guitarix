/*
 * Copyright (C) 2009, 2010 Hermann Meyer, James Warden, Andreas Degert
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef __GX_PAINT_BOX_H__
#define __GX_PAINT_BOX_H__

#include <gtk/gtkbox.h>

G_BEGIN_DECLS

#define GX_TYPE_PAINT_BOX            (gx_paint_box_get_type ())
#define GX_PAINT_BOX(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GX_TYPE_PAINT_BOX, GxPaintBox))
#define GX_PAINT_BOX_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GX_TYPE_PAINT_BOX, GxPaintBoxClass))
#define GX_IS_PAINT_BOX(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GX_TYPE_PAINT_BOX))
#define GX_IS_PAINT_BOX_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GX_TYPE_PAINT_BOX))
#define GX_PAINT_BOX_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GX_TYPE_PAINT_BOX, GxPaintBoxClass))

typedef struct _GxPaintBox GxPaintBox;
typedef struct _GxPaintBoxClass GxPaintBoxClass;



struct _GxPaintBox {
	GtkBox box;

	gchar *paint_func;
	void (*expose_func)(GtkWidget*, GdkEventExpose*);
	guint GSEAL (icon_set) : 16;
};

struct _GxPaintBoxClass {
	GtkBoxClass parent_class;

	GdkPixbuf *gxh_image;
	GdkPixbuf *gxr_image;
	const gchar *stock_id;
	const gchar *main_image_id;
	const gchar *widget_id;
	const gchar *widget_id2;
};

GType gx_paint_box_get_type(void) G_GNUC_CONST;
//GtkWidget *gx_paint_box_new(GtkOrientation orientation, gboolean homogeneous, gint spacing);
GtkWidget *gx_paint_box_new(GtkOrientation orientation, gboolean homogeneous, gint spacing);

G_END_DECLS

#endif /* __GX_PAINT_BOX_H__ */
