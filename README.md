# ProPart2 – Country Literacy Rate BST  
**Author:** Andrew Merritt  
**Language:** C++  
**GitHub Repository:** [AndrewMerri_ProPart2](https://github.com/a0merr/AndrewMerri_ProPart2)  

---

## 📌 Project Overview
This project implements a **Binary Search Tree (BST)** in C++ to store and query **country literacy rates**.  

The program reads a CSV file (`education-economy-data_modified_P2.csv`) containing multiple countries and their corresponding literacy rates.  

Users can:  
- Insert country records into a BST  
- Query the BST to display countries with a **literacy rate above a user-specified threshold**  

The goals of the project were to:  
- Practice **Binary Search Tree implementation** in C++  
- Work with **structs and classes**  
- Read and parse **CSV files**  
- Implement **searching and filtering** using BST traversal  

---

## 🛠️ Files Included
- **Record.h** – Struct representing a country record (ID, country name, literacy rate)  
- **BST.h** – Binary Search Tree class  
  - `Insert()` – Adds a `Record` to the BST based on literacy rate  
  - `PrintRecordsAbove()` – Prints records with values **above a threshold**  
- **main.cpp** – Reads CSV data, inserts records into the BST, and allows threshold-based queries  

---

## ▶️ How to Compile and Run
1. Make sure you have a **C++ compiler** installed (e.g., g++, Visual Studio, clang)  
2. Clone the repository:
   ```bash
   git clone https://github.com/a0merr/AndrewMerri_ProPart2.git
