# Working plan

<!-- vim-markdown-toc GitLab -->

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

<!-- vim-markdown-toc -->

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
- Time and Date functions (useful for random seed generation or time-based
  animations)
- Data Structures (e.g., Lists, Trees, Graphs, if not covered by your
  programming language's standard library)

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
             │                             ▼                             │
             │                     ┌5.───────────┐                       │
             │                     │   Motion    │                       │
             │                     │    Module   │                       │
             │                     └─────────────*                       │
             │                            │                              │
             │           ┌6.───────────┐  │   ┌7.───────────┐            │
             │           │  Utilities  │  │   │   Platform  │            │
             │           │    Module   │  │   │    Module   │            │
             │           └─────┬───────*  ▼   └─────────────*            │
             │                 │    ┌8.───────────┐     │                │
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
