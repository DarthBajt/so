testow = ARGV.empty? ? 1 : ARGV[0].to_i

File.open "dane.txt", "wt" do |f|
  f.write "#{testow}\n"
  testow.times do
    procesow = rand(5..50)
    f.write "#{procesow}\n"
    procesow.times do
      n = rand(1..50)
      f.write "#{n} "
    end
    f.write "\n"
  end
end
