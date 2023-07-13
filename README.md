# so_long

## "don't waste too much time on it" they said ... 

This project is part of the second circle of the 42 common core. The goal is to create a little game. Your objective is to find all collectibles (symbolized by chests) and finish the level by going over the exit while avoiding enemies. It make me learn how to use a graphic librarie and how to create elements of gameplay. You will find the subject of the project into the repository. My grade : 125/100.

![](https://github.com/AnthonyVerdon-42Projects/so_long/blob/master/so_long.gif)
## How to use it

1. Clone it `git clone git@github.com:AnthonyVerdon-42Projects/so_long.git`.
2. Compile it `make`.
3. Start the program by giving a map in argument. You can find some examples in `maps/valid_map/`

## Dependencies

This game has been made with the MinilibX library. You can find into the repository. It use X11.

## How to play

- Movements : `WASD` or arrows
- Quit the game : `Echap` or the red cross
- If you win or lose, you can press `Enter` to restart the game.

## Condition of the map

1. The map must be a square surrounded by walls.
2. All collectibles and the exit must be accessable.
3. There must be an initial position for the player.

| ASCII characters | Equivalence |
| ---------------- | ----------- |
| 0                | Free Space  |
| 1                | Wall        |
| C                | Collectible |
| E                | Map Exit    |
| P                | Player Starting Position |


## Assets

I found the assets on itch.io. If you can, take a loot at the work of these artists !

- Player and enemies : https://o-lobster.itch.io/simple-dungeon-crawler-16x16-pixel-pack?download
- Ground : https://0x72.itch.io/16x16-dungeon-tileset
- Ground, Walls, Chests and Crates: https://0x72.itch.io/dungeontileset-ii?download

## Find a bug ?

If you find an undefined behaviour (crash, leaks, ...), please submit an issue or contact me
