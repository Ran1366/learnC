public class PeopleFactory
{
	public People makePeople(String sex)
	{
		if(sex == "��")
		{
			return new Man();
		}
		if(sex == "Ů")
		{
			return new Woman();
		}
		return null;
	}
}