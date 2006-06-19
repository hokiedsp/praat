/* Distributions_and_Transition.c
 *
 * Copyright (C) 1997-2002 Paul Boersma
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/*
 * pb 1997/03/02
 * pb 2002/07/16 GPL
 */

#include "Distributions_and_Transition.h"

Transition Distributions_to_Transition (Distributions underlying, Distributions surface, long environment,
	Transition adjacency, int greedy)
{
	Transition thee = NULL;
	long i, j, m;
	if (! underlying) return NULL;

	/*
	 * Preconditions: range check and matrix matching.
	 */
	if (environment < 1 || environment > underlying -> numberOfColumns) {
		Melder_error ("Environment (%ld) out of range (1-%ld).", environment, underlying -> numberOfColumns);
		goto end;
	}
	if (surface && (underlying -> numberOfColumns != surface -> numberOfColumns ||
			underlying -> numberOfRows != surface -> numberOfRows))
	{
		Melder_error ("Sizes of underlying and surface distributions do not match.");
		goto end;
	}
	if (adjacency && adjacency -> numberOfStates != underlying -> numberOfColumns) {
		Melder_error ("Number of states (%ld) in adjacency matrix "
			"does not match number of distributions (%ld)",
			adjacency -> numberOfStates, underlying -> numberOfColumns);
		goto end;
	}

	/*
	 * Defaults.
	 */
	if (! surface) surface = underlying;

	/*
	 * Create the output object.
	 */
	thee = Transition_create (underlying -> numberOfColumns); if (! thee) goto end;

	/*
	 * Copy labels and set name.
	 */
	for (i = 1; i <= thy numberOfStates; i ++)
		thy stateLabels [i] = Melder_strdup (underlying -> columnLabels [i]);
	Thing_setName (thee, underlying -> columnLabels [environment]);

	/*
	 * Compute the off-diagonal elements of the transition matrix in environment 'environment'.
	 */
	for (i = 1; i <= thy numberOfStates; i ++) {

		/*
		 * How many states are available for the learner to step to (excluding current state)?
		 */
		long numberOfAdjacentStates;
		if (adjacency) {
			numberOfAdjacentStates = 0;
			for (j = 1; j <= thy numberOfStates; j ++)
				if (i != j && adjacency -> data [i] [j])
					numberOfAdjacentStates ++;
		} else {
			numberOfAdjacentStates = thy numberOfStates - 1;
		}

		/*
		 * Try all possible steps to adjacent states.
		 */
		for (j = 1; j <= thy numberOfStates; j ++) if (i != j) {

			/*
			 * Local: grammar step only possible to adjacent grammar.
			 */
			if (adjacency && adjacency -> data [i] [j] == 0) continue;

			/*
			 * Compute element (i, j): sum over all possible data.
			 */
			for (m = 1; m <= underlying -> numberOfRows; m ++) {

				/*
				 * Error-driven: grammar step only triggered by positive evidence.
				 * If the datum does not conflict with the current hypothesis (i), ignore it.
				 */
				if (underlying -> data [m] [i]) continue;

				/*
				 * Greedy: grammar step only taken if new grammar accepts datum.
				 */
				if (greedy && underlying -> data [m] [j] == 0) continue;

				/*
				 * The step is taken if this datum occurs and this grammar (j) is chosen.
				 */
				thy data [i] [j] += surface -> data [m] [environment] / numberOfAdjacentStates;
			}
		}
	}

	/*
	 * Compute the elements on the diagonal, so that the sum of each row is unity.
	 */
	for (i = 1; i <= thy numberOfStates; i ++) {
		double sum = 0.0;
		for (j = 1; j <= thy numberOfStates; j ++) if (j != i)
			sum += thy data [i] [j];
		thy data [i] [i] = sum > 1.0 ? 0.0 : 1.0 - sum;   /* Guard against rounding errors. */
	}

end:
	if (Melder_hasError ()) {
		forget (thee);
		return Melder_errorp ("(Distributions_to_Transition:) Not performed.");
	}
	return thee;
}

Distributions Distributions_Transition_map (Distributions me, Transition map) {
	Distributions thee = NULL;
	long row, col, m;

	/*
	 * Preconditions: matrix matching.
	 */
	if (map -> numberOfStates != my numberOfRows) {
		Melder_error ("Number of data (%ld) in mapping matrix "
			"does not match number of data (%ld) in distributions",
			map -> numberOfStates, my numberOfRows);
		goto end;
	}

	/*
	 * Create the output object.
	 */
	thee = Data_copy (me);

	/*
	 * Compute the elements of the surface distributions.
	 */
	for (row = 1; row <= my numberOfRows; row ++) for (col = 1; col <= my numberOfColumns; col ++) {
		thy data [row] [col] = 0.0;
		for (m = 1; m <= map -> numberOfStates; m ++)
			thy data [row] [col] += my data [m] [col] * map -> data [m] [row];
	}

end:
	if (Melder_hasError ()) {
		forget (thee);
		return Melder_errorp ("(Distributions_Transition_map:) Not performed.");
	}
	return thee;
}

Distributions Transition_to_Distributions_conflate (Transition me) {
	Distributions thee = Distributions_create (my numberOfStates, 1);
	long i, j;
	if (! thee) goto end;

	/*
	 * Copy labels.
	 */
	for (i = 1; i <= my numberOfStates; i ++)
		thy rowLabels [i] = Melder_strdup (my stateLabels [i]);

	/*
	 * Average rows.
	 */
	for (i = 1; i <= my numberOfStates; i ++) {
		for (j = 1; j <= my numberOfStates; j ++)
			thy data [i] [1] += my data [j] [i];
		thy data [i] [1] /= my numberOfStates;
	}

end:
	if (Melder_hasError ()) {
		forget (thee);
		return Melder_errorp ("(Transition_to_Distributions_conflate:) Not performed.");
	}
	return thee;
}

/* End of file Distributions_and_Transition.c */