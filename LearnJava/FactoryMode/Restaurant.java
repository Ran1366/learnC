public class Restaurant
{
	public static void main(String[] args)
	{
		Kitchen n = new Kitchen();
		ChooseWay w = n.choose("waiter");
		w.choosWay();
		Kitchen m = new Kitchen();
		ChooseWay u = m.choose("computer");
		u.choosWay();	
	}
}