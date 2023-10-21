# General Princicple Concpets

<!-- vim-markdown-toc GitLab -->

* [Introduction](#introduction)
    * [Physics Concepts To be Investigated](#physics-concepts-to-be-investigated)
        * [Statics:](#statics)
        * [Kinetics:](#kinetics)
    * [Method for Numerical Integral](#method-for-numerical-integral)

<!-- vim-markdown-toc -->
## Introduction

In the study of mechanics, particularly when discussing the motion of objects,
the terms "kinematics" and "dynamics" (or "kinetics") refer to different
aspects:

1. **Kinematics**: This is the study of motion without considering the causes
   of the motion. It involves concepts like displacement, velocity,
   acceleration, and time, without any reference to the force causing the
   movement. In other words, kinematics is purely descriptive and doesn't delve
   into the reasons behind the motion.

2. **Dynamics** (or sometimes referred to as **Kinetics**): This is the study
   of motion considering the forces and torques that cause it. Dynamics is further
   divided into:
   - **Statics**: Study of forces in equilibrium (i.e., systems that are not
     accelerating).
   - **Kinetics**: Study of forces in non-equilibrium (i.e., systems that are
     accelerating).

So, in a simplified way:

- **Kinematics**: How things move.
- **Dynamics/Kinetics**: Why things move.


### Physics Concepts To be Investigated

#### Statics:

1. **Equilibrium**: A state where the net force and net moment (torque) on a
   body are zero, leading to no acceleration.
2. **Free Body Diagram (FBD)**: A graphical representation showing all the
   external forces acting on a body.
3. **Support Reactions**: Forces exerted by supports or connections. For
   instance, the reaction force of a table supporting a book.
4. **Moments and Torques**: A force's tendency to rotate an object about an
   axis.
5. **Trusses**: Structures composed of triangular units used in bridges and
   roofs. Static analysis helps determine the forces in each member.
6. **Beams**: Structural elements that primarily resist loads applied laterally
   to the beam's axis. Analysis includes determining shear forces and bending
   moments.
7. **Centroids and Centers of Gravity**: The point where all the weight of an
   object appears to act.
8. **Moments of Inertia**: Measures an object's resistance to changes in its
   rotational motion.

#### Kinetics:

1. **Newton's Second Law**: \( F = ma \), relating force, mass, and
   acceleration.
2. **Linear Motion** (also known as **Translational Motion**): Movement along a
   straight line. Concepts related to this include velocity, acceleration, and
   displacement.
3. **Rotational Motion**: Movement around an axis. Concepts include angular
   velocity, angular acceleration, and moments of inertia.
4. **Work and Energy**: Concepts related to the work done by forces and the
   conservation of energy.
5. **Momentum and Impulse**: Concepts involving the product of mass and
   velocity, and how forces acting over time can change momentum.
6. **Drag Force**: A resistive force acting opposite to the object's relative
   motion through a fluid (like air or water).
7. Friction: The force resisting the relative motion of solid surfaces,
   fluid layers, or material elements sliding against each other.
8. **Simple Harmonic Motion**: The motion of an object oscillating back and
   forth, such as a pendulum or a mass on a spring.
9. **Damped and Forced Vibrations**: Situations where external forces or
   resistive forces (like drag or friction) influence an object's natural
   vibrations.

### Method for Numerical Integral

| **Method Name**                      | **Description**                                                                                                                                                                                                   |
| ------------------------------------ | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Euler's Method**                   | A first-order method where the new position is found by adding the current velocity multiplied by a time step to the current position.                                                                            |
| **Improved Euler's (Heun's Method)** | An improved version of Euler's method which uses an average of the slopes at the beginning and end of the interval to update the state.                                                                           |
| **Midpoint Method**                  | Uses the slope at the midpoint of the interval to update the state, providing a more accurate estimate than the basic Euler's method.                                                                             |
| **Runge-Kutta 4th order (RK4)**      | A widely used method that takes four estimates of the slope (at the beginning, two at the midpoint, and one at the end) to update the state. It's more accurate than the previous methods for the same time step. |
| **Verlet Integration**               | Especially useful for problems of molecular dynamics. It uses positions and accelerations, but not velocities, which can make it more stable for certain types of problems, like many-body simulations.           |
| **Leapfrog Method**                  | A variation of Verlet that stores velocities and positions staggered in time, which can improve energy conservation in certain simulations.                                                                       |
| **Velocity Verlet**                  | A modified version of the Verlet method that also provides velocities, making it useful for systems where velocities are required, e.g., for temperature calculations in molecular dynamics.                      |

Each method has its advantages and drawbacks in terms of accuracy, stability,
and computational cost. The choice of method can depend on the specific problem
at hand, its requirements, and the desired balance between accuracy and
computational efficiency.

