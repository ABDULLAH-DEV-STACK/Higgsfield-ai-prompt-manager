# C++ Higgsfield AI Prompt & Database Manager

A high-performance, embedded console application designed to handle relational data persistence and structure API dispatch layers for generative AI engineering workflows. Built using modern C++ Object-Oriented Programming (OOP) paradigms and integrated directly with an optimized, serverless relational database engine.

---

## 🎯 Target Engineering Competencies
This repository has been engineered to showcase critical production-level practices valued in enterprise scale ecosystems (such as those at **Volvo Group** and **Ericsson**):
* **Zero-Friction Portability:** Adheres to strict compilation structures ensuring instant deployment on any compliant target machine without background daemon installations.
* **Database Security & Sanitization:** Mitigation of relational vulnerabilities via strict prepared statements and parameter binding protocols.
* **Low-Level Memory Safety:** Manual allocation control, resource cleanup routines, and type-safe data streaming in unmanaged runtime environments.

---

## 🛠️ System Architecture & Features

### 1. Embedded Relational Data Architecture
* **Self-Contained Storage Engine:** Integrates **SQLite3** directly into the binary core using the optimized **Amalgamation** distribution package. It maintains zero runtime system requirements by writing entire relation structures into a single file wrapper (`ai_prompts.db`).
* **DDL Automation:** The system initializes table schemas (`VideoJobs`) dynamically upon instantiating infrastructure dependencies, safely evaluating configurations at launch.

### 2. Enterprise-Grade Query Safety (Defensive Programming)
* **SQL Injection Mitigation:** Replaces high-risk string concatenations with native database prepared statements via `sqlite3_prepare_v2`.
* **Safe Parsing Engine:** Binds input parameters using type-safe reference wrappers (`sqlite3_bind_text`). This allows smooth ingestion of complex strings containing distinct control symbols, quotes, or formatting layouts without database runtime exceptions.

### 3. Bi-Directional CRUD Pipeline
* **Disk Persistence Pipeline (Create):** Captures incoming terminal inputs and flushes structural text blocks down to the target block storage devices, tagging data assets with an audit state (`PENDING_API_CALL`).
* **Data Recovery Interface (Read):** Performs memory queries to retrieve raw binary objects out of disk cells, dynamically casting values into standard C++ abstractions while loops stream rows back onto the presentation layout.

### 4. Modular Object-Oriented Layout
* **`DatabaseManager` Class:** Encapsulates the complete database system footprint. Manages explicit connection handles (`sqlite3*`), dynamic pointer validation logs, query statements, and destructor cleanup routines (`sqlite3_finalize`, `sqlite3_close`) to completely eliminate memory leak footprints.
* **`HiggsfieldClient` Class:** Abstracts enterprise communication models, managing configuration properties, API routing rules, and credential scopes while preparing simulated transmission structures to external backend APIs.

---

## 💻 Core Technical Stack
* **Language Core:** C++ (Object-Oriented Programming, Memory Management, I/O Data Streams)
* **Database Engine:** SQLite3 (ANSI SQL Compliant, Embedded Serverless Architecture)
* **Compilation Framework:** GNU Compiler Collection (GCC Toolkit)
* **Version Control Protocol:** Git Workspace Architecture (Clean distribution rules applied using `.gitignore`)

---

## 🏗️ Architectural Class Model

```text
 ┌────────────────────────────────────────────────────────┐
 │                     Application Loop                   │
 └───────────────────────────┬────────────────────────────┘
                             │
              ┌──────────────┴──────────────┐
              ▼                             ▼
   ┌────────────────────┐        ┌────────────────────┐
   │  DatabaseManager   │        │ HiggsfieldClient   │
   ├────────────────────┤        ├────────────────────┤
   │ ── sqlite3* db     │        │ ── string apiKey   │
   │ ── savePrompt()    │        │ ── dispatchPrompt()│
   │ ── readAllPrompts()│        └────────────────────┘
   └────────────────────┘
```

---

## 🚀 Compilation & Build Instructions

To ensure seamless compilation validation and bypass modern C++ strict type-checking warnings during multi-paradigm builds on platforms like Windows or Linux, the project separates C engine translation from C++ pipeline compilation.

### Step 1: Translate the C Database Engine Binaries
Compile the core SQLite code using the standard C compiler to produce a clean machine-level object file:
```bash
gcc -c sqlite3.c -o sqlite3.o
```

### Step 2: Link the Application Binaries
Use the C++ compiler to translate the primary runtime application and link the temporary database architecture directly into the final execution binary:
```bash
g++ main.cpp sqlite3.o -o prompt_manager
```

### Step 3: Launch the Runtime System
Execute the compiled production binary:
```bash
./prompt_manager
```

---

## 📂 Repository File Index
* **`main.cpp`** - Core application runtime, program menu pipelines, and class definitions.
* **`sqlite3.c` / `sqlite3.h`** - Industrial Amalgamation build source of the SQLite3 database engine.
* **`.gitignore`** - Explict file filters ensuring build artifacts (`*.o`, `*.exe`, `prompt_manager`) and local storage components (`*.db`) remain omitted from version tracking histories.
* **`README.md`** - Production documentation overview.

