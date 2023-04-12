import java.util.LinkedList;

public class SynchronisedProducerAndConsumer {

	public static void main(String[] args)throws InterruptedException {
		// Creating object of a class(producerandconsumer) that has both produce()
					// and consume() methods

		final ProducerAndConsumer pc = new ProducerAndConsumer();

		// Creating  producer thread
		Thread Firstone = new Thread(new Runnable() {
			@Override
			public void run()
			{
				try {
					pc.produce();
				}
				catch (InterruptedException e) {
								e.printStackTrace();
				}
			}
		});

		// Create consumer thread
		Thread Secondone = new Thread(new Runnable() {
				@Override
				public void run()
				{
					try {
						pc.consume();
					}
					catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
		});

					// Start both threads
		Firstone.start();
		Secondone.start();
		Firstone.join();
		Secondone.join();
					// t1 finishes before t2
		
		
		System.out.println("Finished");

	}

}
