public class PeopleFactory
{
	public People makePeople(String sex)
	{
		if(sex == "ÄÐ")
		{
			return new Man();
		}
		if(sex == "Å®")
		{
			return new Woman();
		}
		return null;
	}
}