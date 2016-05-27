
MAX = 1000
MAX_ODWOLAN = 100

wielkosc_dysku = ARGV.empty? ? MAX : ARGV[0].to_i
przemieszczen = ARGV.empty? ? MAX_ODWOLAN : ARGV[1].to_i

File.open "dane.txt", "wt" do |f|
  f.write "#{wielkosc_dysku}\n#{rand(1..wielkosc_dysku)}\n#{przemieszczen}\n"
  przemieszczen.times do
    f.write "#{rand(1..wielkosc_dysku)} "
  end
  f.write "\n"
end
