# Langton's Ant (C + SDL2)

A visualization of **Langton's Ant**, a two-dimensional universal Turing machine with a very simple set of rules but complex emergent behavior. Built using **C** and the **SDL2** library within the **Visual Studio** environment.

### 🎥 Example Video

Check out the simulation in action:


https://github.com/user-attachments/assets/de15b6e3-4504-4070-9357-7576374a6059



---

## 🐜 Logic & Rules

The ant starts on a grid of white cells and moves according to these rules:

* **On a white square:** Turn 90° right, flip the color of the square to black, and move forward.
* **On a black square:** Turn 90° left, flip the color of the square to white, and move forward.

After about 10,000 steps, the ant enters a "highway" phase, creating a diagonal corridor.

## 🛠️ Built With

* **Language:** C
* **Graphics:** SDL2 (Simple DirectMedia Layer)
* **IDE:** Visual Studio 2022

## 🚀 Setup & Installation (Visual Studio)

1. **Clone the repository:**
```bash
git clone https://github.com/hesenbeyy/LangtonsAnt

```


2. **Open the Project:**
Double-click the `.sln` file to open the project in Visual Studio.
3. **SDL2 Configuration:**
* Ensure the **Include** and **Library** directories in your Project Properties point to your SDL2 folder.
* Make sure `SDL2.dll` is in the same folder as your generated `.exe` (usually `Debug` or `Release` folders).


4. **Build & Run:**
Press `F5` to start the simulation.

## 📦 Releases

**I have shared a release.** The release includes the standalone executable and the necessary DLLs so you can run the program immediately without needing to install SDL2 or Visual Studio.

## ⚙️ Configuration

You can tweak the simulation behavior in `macros.h`:

* `TILES`: Changes the window dimensions.
* `CELL_SIZE`: Adjusts the scale of the grid (lower numbers create a more detailed "highway").
