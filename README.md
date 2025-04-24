# 🚀 Asteroid Destroyer

A retro-style arcade game built in C++. Pilot your spaceship, dodge asteroids, and blast your way to survival!

---

## 🎮 Game Features

- Classic 2D arcade-style shooter
- Simple keyboard controls
- Random asteroid spawning and motion
- Collision detection and score tracking

---

## 🕹️ How to Play

- **Arrow Keys**: Move your spaceship
- **Spacebar**: Fire weapon
- Destroy as many asteroids as possible without crashing!

---

## 🔧 Build Instructions

```bash
g++ -o asteroid_destroyer main.cpp player.cpp asteroid.cpp bullet.cpp -lSDL2
./asteroid_destroyer
```

> Ensure you have SDL2 & SFML installed before building.

---

## 🧠 Code Overview

- `main.cpp` – Initializes SDL, runs the game loop, handles rendering and events.
- `player.cpp / player.h` – Defines the spaceship class and controls its movement.
- `asteroid.cpp / asteroid.h` – Manages asteroid spawning, movement, and collision logic.
- `bullet.cpp / bullet.h` – Handles shooting mechanics and bullet collisions.

---

## 🚧 Future Enhancements

- Add sound effects and background music
- Power-ups and new enemy types
- High score saving

---

## 📜 License

MIT License – feel free to modify and build on it!
