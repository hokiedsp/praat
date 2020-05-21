#ifndef _FormantModelerList_h_
#define _FormantModelerList_h_
/*FormantModelerList.h
 *
 * Copyright (C) 2020 David Weenink
 *
 * This code is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This code is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this work. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Collection.h"
#include "Function.h"
#include "FormantModeler.h"
#include "FormantPath.h"
#include "FormantList.h"
#include "Graphics.h"
#include "melder.h"

#include "FormantModelerList_def.h"

autoFormantModelerList FormantPath_to_FormantModelerList (FormantPath me, double startTime, double endTime, conststring32 numberOfParametersPerTrack_string);
autoFormantModelerList FormantList_to_FormantModelerList (FormantList me, double startTime, double endTime, conststring32 numberOfParametersPerTrack_string); // to be removed


/* For special drawings, like the FormantEditor */

autoFormantModelerListDrawingSpecification FormantModelerList_to_FormantModelerListDrawingSpecification (FormantModelerList me, integer special);

integer FormantModelerListDrawingSpecification_getNumberOfShown (FormantModelerListDrawingSpecification me);

void FormantModelerListDrawingSpecification_showAll (FormantModelerListDrawingSpecification me);

void FormantModelerList_markBest3 (FormantModelerList me);
void FormantModelerList_showBest3 (FormantModelerList me);
autoINTVEC FormantModelerList_getBest3 (FormantModelerList me);

void FormantModelerList_getMatrixGridLayout (FormantModelerList me, integer *out_numberOfRows, integer *out_numberOfColums);

void FormantModelerList_drawInMatrixGrid (FormantModelerList me, Graphics g, integer nrow, integer ncol, kGraphicsMatrixOrigin origin, double spaceBetweenFraction_x, double spaceBetweenFraction_y, integer fromFormant, integer toFormant, double fmax, double yGridLineEvery_Hz, double xCursor, double yCursor, integer numberOfParameters, bool drawErrorBars, double barwidth_s, double xTrackOffset_s, bool drawEstimated, bool garnish);

#endif /* _FormantModelerList_h_ */
