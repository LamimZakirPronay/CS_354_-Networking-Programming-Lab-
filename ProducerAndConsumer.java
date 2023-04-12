

import java.util.LinkedList;

public class ProducerAndConsumer {

//Create a commonstorage shared by producer and consumer methods which also works as a buffer 
//Size of commonstorage is 1.

			LinkedList<Integer> commonstorage = new LinkedList<>();
			int capacity = 2;
			
		
				// Method called by producer thread
				public  void produce() throws InterruptedException
				{
					int value=0;
					while (value<10) {
						synchronized(this) {
// producer thread waits while commonstorage is full 
							
							while (commonstorage.size() == capacity)
								wait();
							
value=value+1;
System.out.println("Producer has produced-"
											+ value);
// to insert the value in the commonstorage
							
							commonstorage.add(value);
// informs  the consumer thread that  it can now initiate consuming
							notify();

						 
							Thread.sleep(10);
						}}
					}
				public  void consume() throws InterruptedException
				{
					
					while (true) {
						synchronized(this) {

// producer thread waits while commonstorage is full 
							
							while (commonstorage.size() == 0)
								
								wait();
							
								int val = commonstorage.removeFirst();
								 
			                    System.out.println("Consumer consumed-"
			                                       + val);
							
// informs  the consumer thread that  it can now initiate consuming
						
							notify();

						 
							Thread.sleep(10);
						}
					
					
					}					
					
					
					
					
					
					
					
	// Method called by consumer thread
				
		
	}
}


			


		

