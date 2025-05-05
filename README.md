Voici un **README.md** adapté à ton projet de casse-brique, basé sur le code que tu as partagé. Tu peux le coller directement dans un fichier `README.md` à la racine de ton dépôt GitHub.

---

# 🕹️ Casse-Brique (Breakout) en C avec SDL2

Un jeu classique de **casse-brique** développé en **C pur**, utilisant la bibliothèque graphique **SDL2**.

---

## 📋 Description du Projet

Ce projet implémente un jeu de type **Breakout / Arkanoid**, où le joueur doit détruire des briques avec une balle en la contrôlant grâce à une barre située en bas de l’écran.

### Fonctionnalités :

- Système de briques 2D
- Balle principale et balle bonus
- Interface utilisateur simple (vies, écrans de démarrage/fin)
- Power-up : étoile qui active la balle bonus
- Contrôles clavier simples (`Q`, `D`, `ESPACE`)
- Gestion d'événements souris pour le menu

---

## 🧰 Prérequis

Pour compiler ce projet, vous aurez besoin :

### Sur tous les systèmes :

- Un compilateur C (`gcc`)
- La bibliothèque [SDL2](https://www.libsdl.org/download-2.0.php)
- La bibliothèque [SDL2_image](https://www.libsdl.org/projects/SDL_image/)

---

## 🚀 Installation

### Étape 1 : Cloner le dépôt

```bash
git clone https://github.com/konchu974/Brick-Breaker.git
cd Brick-Breaker
```

### Étape 2 : Installer les dépendances

#### 🔹 Sur Linux (Debian/Ubuntu) :

```bash
sudo apt install libsdl2-dev libsdl2-image-dev gcc
```

#### 🔹 Sur macOS (Homebrew) :

```bash
brew install sdl2 sdl2_image
```

#### 🔹 Sur Windows (MSYS2/MinGW64) :

```bash
pacman -S mingw-w64-x86_64-SDL2 mingw-w64-x86_64-SDL2_image
```

---

## ⚙️ Compilation

```bash
gcc -o cassebrique main.c function.c -lSDL2 -lSDL2_image -mconsole -DSDL_MAIN_HANDLED
```

> Si vous n'avez pas encore de fichier `function.c`, assurez-vous de l'avoir dans le même dossier que `main.c`.

---

## ▶️ Lancement

### Sur Linux/macOS :

```bash
./cassebrique
```

### Sur Windows :

Assurez-vous que les fichiers `.dll` suivants sont dans le même dossier que votre exécutable :

- `SDL2.dll`
- `SDL2_image.dll`

Puis lancez :

```bash
cassebrique.exe
```

---

## 🎮 Contrôles

| Action            | Touche   |
| ----------------- | -------- |
| Déplacer à gauche | `Q`      |
| Déplacer à droite | `D`      |
| Démarrer la balle | `ESPACE` |
| Quitter           | `ÉCHAP`  |

---

## 🖼️ Assets requis

Le jeu utilise des images stockées dans le dossier `assets/`. Assurez-vous qu’il contient ces fichiers :

- `images/ecran_base_fs.bmp`
- `images/menu_start_fs1.bmp`
- `images/pngwing.com.bmp`
- `images/Design-sans-titre.bmp`
- `images/Game-over.bmp`
- `images/star.bmp`

> ⚠️ Si vos images sont dans un dossier nommé `images/` au lieu de `assets/`, modifiez les chemins dans le code.

---

## 📁 Structure du projet

```
.
├── main.c          # Logique du jeu (balles, briques, boucle principale)
├── function.c      # Fonctions graphiques (dessin, image, etc.)
├── function.h      # Fichier d'en-tête
├── assets/         # Dossier contenant les images (.bmp)
└── README.md       # Ce fichier
```

---

## 💡 Idées d'améliorations futures

- Charger des images au format PNG avec `IMG_Load()`
- Ajouter des sons avec `SDL_mixer`
- Créer un vrai menu principal (options, crédits)
- Sauvegarder les scores dans un fichier
- Améliorer les animations entre les états du jeu

---
