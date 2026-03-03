A minimal inter-process communication (IPC) chat application using **POSIX shared memory** and **semaphores** in C.

Overview

SharedChat demonstrates how two processes can communicate in real-time using:
One process writes messages, the other reads them — simple and elegant!

Build

```bash
make
```

This compiles both `writer` and `reader` executables.

To clean up:
```bash
make clean
```

Usage

**Important:** Always run the **writer first!** It initializes the shared memory and semaphores.

### Terminal 1 — Start the Writer
```bash
./writer <username>
```
Example:
```bash
./writer Noro
```

### Terminal 2 — Start the Reader
```bash
./reader
```

## 📝 Example

**Writer (Terminal 1):**
```
$ ./writer Noro
Noro: Hello!
Noro: How are you?
```

**Reader (Terminal 2):**
```
$ ./reader
Other: Hello!
Other: How are you?
```