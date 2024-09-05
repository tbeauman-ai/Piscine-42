$size = int($ARGV[0]);
$i = 0;
print("\"");
while ($i < 4)
{
	$j = 0;
	while ($j < $size)
	{
		print(int(rand($size)) + 1);
		if ($j < $size - 1 || $i < 3)
		{
			print(' ');
		}
		$j++;
	}
	$i++;
}
print("\"");

