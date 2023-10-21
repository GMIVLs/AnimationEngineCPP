# Working plan

<!-- vim-markdown-toc GitLab -->

* [Introduction](#introduction)
    * [General concepts](#general-concepts)
* [2D Simulator & Animation Engine](#2d-simulator-animation-engine)
* [Requirements](#requirements)
    * [Project Strucuture](#project-strucuture)
    * [1. Math Module:](#1-math-module)
    * [2. Stats Module:](#2-stats-module)
    * [3. Platform Module:](#3-platform-module)
    * [4. Motion Module:](#4-motion-module)
    * [5. Utilities Module:](#5-utilities-module)
    * [6. Experiments Module:](#6-experiments-module)
    * [Table with Characteristics:](#table-with-characteristics)
    * [Graphics Architecture Diagram:](#graphics-architecture-diagram)
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

### General concepts

## 2D Simulator & Animation Engine

The proposed strategy involves initially establishing particle system
functionality in two dimensions by focusing on statics and then gradually
expanding to incorporate dynamic features. To achieve this, we will initially
work with linear motion within that plane as a foundation for creating more
intricate animations in two-dimensional spaces.

## Requirements

Let us begin by establishing a preliminary structure that can be expanded upon
in greater detail as we progress.

### Project Strucuture

### 1. Math Module:

- linear algebra
  - Vectors
  - Matrices
  - Tensors
  - Quaternions
  - ..etc.
- Numerical Analysis
  - Integral formula
    - Simple linear integral (see below)
    - Rang-kutta integral
    - etc..
  - Differential formula

### 2. Stats Module:

- Probability:
  - Probability and their distributions
  - Monte carlo simulation
- Random Generator
- Statistical Analysis (e.g., mean, median, mode, standard deviation)
  - Random event generator

### 3. Platform Module:

- Environment
  - Canvas Creation
  - Colors
  - Images
  - Fonts
- Animation (FPS and other related characteristics)
- User Input (e.g., keyboard and mouse interaction)
- Sound ..etc.
- Time
  - Time detla
  - FPS (Hz)

### 4. Motion Module:

- Particle2D (for 2D motion)
- Force (e.g., gravitational, electromagnetic)
- Kinematics (e.g., velocity, acceleration functions)
- Collisions (e.g., detection and response)

### 5. Utilities Module:

- File IO (reading/writing data)
- Error Handling and Logging
- Time and Date functions (useful for random seed generation or time-based animations)
- Data Structures (e.g., Lists, Trees, Graphs, if not covered by your programming language's standard library)

### 6. Experiments Module:

- Simulation (running and visualizing motion or statistical simulations)
- Plotting (graphing results, if not covered under Canvas in the Platform module)
- User Interface (basic UI for user to choose and run experiments)

### Table with Characteristics:

| Module      | Characteristics                                                |
| ----------- | -------------------------------------------------------------- |
| Math        | Vector operations, Matrix operations, etc.                     |
| Stats       | Probability functions, Random number generation, etc.          |
| Platform    | Canvas setup, Color definitions, Font management, etc.         |
| Motion      | Particle behavior, Force definitions, Collision handling, etc. |
| Utilities   | File operations, Error logging, Time functions, etc.           |
| Experiments | Run simulations, Plotting tools, UI for user experiments, etc. |

### Graphics Architecture Diagram:

```lua
             ┌───────────────────────────────────────────────────────────┐
             │           ┌1.──────┐ ┌2.──────┐ ┌3.──────┐                │
             │           │ Physics│ │ Math   │ │ stats  │                │
             │           │ Module │ │ Module │ │ Module │                │
             │           └─────┬──* └─────┬──* └─────┬──*                │
             │                 │          ▼          │                   │
             │                 │     ┌4.───────┐     │                   │
             │                 │     │ Particle│◀────┘                   │
             │                 └────▶│ Module  │                         │
             │                       └─────┬───*                         │
             │                             │                             │
             │           ┌5.───────────┐   │  ┌6.───────────┐            │
             │           │  Utilities  │   │  │   Platform  │            │
             │           │    Module   │   │  │    Module   │            │
             │           └─────┬───────*   ▼  └─────────────*            │
             │                 │    ┌7.───────────┐     │                │
             │                 └──▶ │ Experiments │     │                │
             │                      │    Module   │◀────┘                │
             │                      └─────┬───────*                      │
             │                            ▼                              │
             │                 ┌───────────────────────┐                 │
             │                 │       `2d` Canvus     │                 │
             │                 │    Graphics Display   │                 │
             │                 └───────────────────────*                 │
             │                               2D - graphics architecture  │
             └───────────────────────────────────────────────────────────┘
```

| **Module/Feature**                | **Characteristics/Components**                                                                                                                  |
| --------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| **Renderer Module**               | - Drawing Primitives (lines, circles, rectangles) <br/> - Texture Management <br/> - Layering and Depth <br/> - Batch Rendering <br/> - Shaders |
| **Asset Management**              | - Asset Loader <br/> - Resource Management <br/> - Sprite Management                                                                            |
| **Animation Module**              | - Sprite Animation <br/> - Tweening <br/> - Particle Systems                                                                                    |
| **Audio Module**                  | - Music Playback <br/> - Sound Effects <br/> - Volume Control                                                                                   |
| **Physics Module**                | - Collision Detection <br/> - Physics Simulation <br/> - Bounding Boxes                                                                         |
| **Input Management**              | - Keyboard Input <br/> - Mouse Input <br/> - Touch Input                                                                                        |
| **Scene Management**              | - Scene Graph <br/> - Camera <br/> - Transitions                                                                                                |
| **User Interface (UI) Module**    | - Buttons and Controls <br/> - Menus <br/> - HUD (Heads-Up Display)                                                                             |
| **Scripting and Event System**    | - Scripting Integration <br/> - Event System                                                                                                    |
| **Networking**                    | - Client-Server Architecture <br/> - Real-time Sync <br/> - Lobbies and Matchmaking                                                             |
| **Debugging and Profiling Tools** | - Debug Overlay <br/> - Logging System <br/> - Performance Profiling                                                                            |
| **Documentation**                 | - Detailed documentation for each module, function, and class.                                                                                  |

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
