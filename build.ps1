function Run {

    $mainPath = "./main.cpp"
    $outputPath = "./bin/debug/game.exe"
    $includePath = "./include"

    $mingw_path = "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64"

    $libraryPaths = ($mingw_path + "/include"), ($mingw_path + "/lib")
    $libraries = "lmingw32", "lSDL2main", "lSDL2", "lSDL2_image", "mwindows"

    $expressionString = MakeBuildExpression -Main $mainPath -Output $outputPath -Include $includePath -LibraryPaths $libraryPaths -Libraries $libraries

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
        [string] $Include,
        [Parameter(Mandatory = $false, Position = 3)]
        [string[]] $LibraryPaths,
        [Parameter(Mandatory = $false, Position = 4)]
        [string[]] $Libraries
    )

    $compileExpression = "g++", ("""" + $Main + """"), "-o", ("""" + $Output + """")

    $includeFiles = Get-ChildItem -Path $Include -Filter *.cpp -Recurse -Name
    foreach ($file IN $includeFiles) {
        $cppFile = $Include + "/" + $file
        $expressionArgument = "-g", ("""" + $cppFile + """")

        $compileExpression = $compileExpression + $expressionArgument
    
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