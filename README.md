# Usage information

For secure and efficient use of this program, please ensure that the file to be processed is located in the same directory as the program executable. This requirement is established to mitigate several security and operational risks, including but not limited to:

- **Path Traversal:** Ensuring the file is in the same directory restricts the potential for path traversal attacks, which might attempt to access or manipulate files in unintended directories.

- **Unauthorized File Access:** Limiting file access to a specific directory helps prevent unintended reading, writing, or manipulation of sensitive files elsewhere on the system.

- **Resource Management:** Managing files in the same directory simplifies resource management and ensures that the program operates within its designed parameters, maintaining system stability and performance.

- **Data Integrity:** Keeping the file in the program's directory helps safeguard data integrity by reducing the likelihood of referencing or altering incorrect or unintended files.
