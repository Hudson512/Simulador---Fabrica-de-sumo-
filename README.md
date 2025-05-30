# Simulator: Juice Factory
![Gemini_Generated_Image_wiotblwiotblwiot](https://github.com/user-attachments/assets/0299f9b2-04ee-416b-8e23-8779c2ade0f6)

A juice filling factory needs to purchase new machines for its production. 
Before the purchase, the board of directors decided to commission the development of a simulation to assess the production level. The simulation consists of the following:


• The factory fills two different sizes of juice packages: 200 ml (PA) and 1 L (PB). There are two queues for each package, representing each phase of the process. The first queue is for filling, and the second is for packaging. Each queue is associated with a machine;


• A production machine (filling, packaging, and stacking) should be represented by an ADT (Abstract Data Type) that contains the name, type of machine, processing time, the number of units processed in a production day, the queue of products to be processed, and any other necessary attributes;


• Packages are inserted into the initial queue (one queue for each package type);


• PA packages (200 ml) leave the queue and enter the filling machine. After filling, the packages proceed in a queue to the packaging machine in sets of 6. If there are not yet 6 packages in the machine, packaging cannot occur. After leaving the machine, already grouped in 6, the packages are stacked. The stacking machine stacks up to 4 boxes of 6 packages each;


• PB packages (1 L) follow the same process as PA, with the difference that they are packaged in groups of 4 and stacked up to 3 boxes;


• Each package has its own characteristics that determine whether it is suitable for packaging. If a package is out of standard (e.g., incorrect type or weight), it is discarded from the queue and not included in the process.
