function Run {

    $mainPath = "./main.cpp"
    $outputPath = "./build/debug/game.exe"
    $includePaths = "./include", "./src"

    $mingw_path = "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64"

    $libraryPaths = ($mingw_path + "/include"), ($mingw_path + "/lib")
    $libraries = "lmingw32", "lSDL2main", "lSDL2", "lSDL2_image", "mwindows"

    $expressionString = MakeBuildExpression -Main $mainPath -Output $outputPath -IncludePaths $includePaths -LibraryPaths $libraryPaths -Libraries $libraries

    Write-Host "Building..."
    Write-Host "========================"
    Write-Host ""
    Write-Host $expressionString
    Write-Host ""

    Invoke-Expression $expressionString

    Write-Host "========================"
    Write-Host "Done."
    Write-Host ""
}
function MakeBuildExpression {
    Param
    (
        [Parameter(Mandatory = $true, Position = 0)]
        [string] $Main,
        [Parameter(Mandatory = $true, Position = 1)]
        [string] $Output,
        [Parameter(Mandatory = $false, Position = 2)]
        [string[]] $IncludePaths,
        [Parameter(Mandatory = $false, Position = 3)]
        [string[]] $LibraryPaths,
        [Parameter(Mandatory = $false, Position = 4)]
        [string[]] $Libraries
    )

    $compileExpression = "g++", ("""" + $Main + """"), "-o", ("""" + $Output + """")

    foreach($include IN $IncludePaths)
    {
        $includeFiles = Get-ChildItem -Path $include -Filter *.cpp -Recurse -Name
        foreach ($file IN $includeFiles) {
            $cppFile = $Include + "/" + $file
            $expressionArgument = "-g", ("""" + $cppFile + """")
    
            $compileExpression = $compileExpression + $expressionArgument
        
        }
    }
    foreach ($libDir IN $LibraryPaths)
    {
        $libArg = "-I" + ("""" + $libDir + """")
        $compileExpression = $compileExpression + $libArg
    }
    foreach ($lib IN $Libraries)
    {
        $libArg = "-" + $lib
        $compileExpression = $compileExpression + $libArg
    }

    $expressionString = [system.String]::Join(" ", $compileExpression)
    Write-Output $expressionString
}

# Call Run()
Run