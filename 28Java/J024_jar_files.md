### What are jar files ?

It's a common way to bundle Java applications or libraries into a single, compressed archive file for easier distribution and deployment. Here are some key points about JAR files:

1. **Container for Java Classes:** JAR files can contain compiled Java class files, which are the bytecode that Java applications run on.

2. **Resources and Metadata:** In addition to class files, JAR files can also include other resources like images, configuration files, XML files, and metadata files (such as Manifest files).

3. **Compression:** JAR files are typically compressed using the ZIP file format. This compression reduces the file size and makes it more efficient for distribution and downloading.

4. **Executable and Library JARs:** There are two main types of JAR files: executable JARs and library JARs.

   - **Executable JAR:** An executable JAR contains a manifest file specifying the main class to be executed when the JAR is run. This makes it possible to distribute and run standalone Java applications from a single JAR file.
   - **Library JAR:** A library JAR contains reusable Java classes and resources that can be used by other Java applications. These JARs are typically added to a Java project's classpath to make the contained classes accessible.

5. **Classpath:** Java applications can reference JAR files on their classpath to access classes and resources contained within them. This makes it easy to reuse and share code across different projects.

6. **Versioning:** JAR files can include version information, making it possible to manage different versions of libraries and applications.

### To run a jar file use => java -jar YourJarFile.jar
