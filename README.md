# Zorang-FT-Project

Algorithm that i've used here:-

1.	curr_pos[i] stores the coordinates on which the ith delivery agent is currently standing (initally curr_pos[i] is equal to the coordinates of the store). 
2.	dist_so_far[i] stores the distance which the ith delivery agent has travelled so far.
3.	Every moment, we will find the nearest unvisited delivery location for all the delivery agents from their current positions, note that for calculating the nearest delivery location we will also account for the distance that the delivery agents have travelled so far.
4.	We will then pick that delivery agent which has the closest delivery location among all the agents, move him to the new delivery location and update curr_pos and dist_so_far array.
5.	After all the delivery locations have been visited, we will then move the delivery agents from their curr_pos to the store.
