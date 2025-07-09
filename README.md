# 🌐 Fullstack Svelte + Crow C++ Template

A fullstack starter template featuring:

- ⚡ **Svelte** (frontend with Vite)
- 🦅 **Crow** (backend in C++)
- 🐘 PostgreSQL integration with `libpq`
- 📦 Simple environment-based configuration
- 🛠️ Minimal, fast, and scalable fullstack setup

---

## 📁 Project Structure

fullstack-template/
├── client/ # Svelte frontend
├── server/ # Crow backend (C++)
└── README.md


---

## 🚀 Setup Guide

### 📦 Prerequisites

- Node.js (https://nodejs.org/)
- CMake (https://cmake.org/)
- g++ or Visual Studio Build Tools
- PostgreSQL installed & running
- libpq installed (PostgreSQL client lib)

---

### 🔧 1. Clone the Repository

```
git clone https://github.com/yourusername/fullstack-template.git
cd fullstack-template
```

### 🌐 2. Frontend Setup (Svelte)

```cd client
npm install
npm run dev```


This will run the frontend at: http://localhost:5173

---

### 🖥️ 3. Backend Setup (Crow + PostgreSQL)

```cd ../server
mkdir build && cd build
cmake ..
cmake --build .
./crow-template```

The backend will run at: http://localhost:2000

---

### 🔐 4. Create `.env` file inside `server/`

```PG_HOST=localhost
PG_PORT=5432
PG_DB=kanbique
PG_USER=postgres
PG_PASSWORD=yourpassword```

---

### 🧪 Test the Backend API

```curl http://localhost:2000/api/hello```

Expected output:

{ "message": "Hello from Crow!" }


---

## 📦 Production Build

### Build Frontend

```cd client
npm run build```

### Build Backend (Release mode)

```cd ../server/build
cmake --build . --config Release```


You can configure Crow to serve the frontend static files from `client/dist`.

---


## 🙌 Acknowledgements

- Crow C++ Framework — https://crowcpp.org/
- Svelte — https://svelte.dev/
- PostgreSQL — https://www.postgresql.org/
- Vite — https://vitejs.dev/