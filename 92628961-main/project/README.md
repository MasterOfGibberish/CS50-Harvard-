# JUNK_MASE.com (a web-based application using JavaScript, Python, and SQL (AND C# and XAML))
##### Video Demo: https://youtu.be/gl2RXGAlFig
##### Description: My Final Project is a web-based application using JavaScript, Python, and SQL where you can download the program made using C# and XAML. It has a login page where users enter their username and password to gain access to the application. Once logged in, users may be directed to a welcome page, which serves as the main page of the application.

##### Sqlachemy and sqlite3c(this part was the hardest because I had never worked with it bedore):

##### There are table where I put, id, first_name (Name), password and email, notice that id must be a primary key here.


models.py

class Note(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    data = db.Column(db.String(10000))
    date = db.Column(db.DateTime(timezone=True), default=func.now())
    user_id = db.Column(db.Integer, db.ForeignKey('user.id'))


class User(db.Model, UserMixin):
    id = db.Column(db.Integer, primary_key=True)
    email = db.Column(db.String(150), unique=True)
    password = db.Column(db.String(150))
    first_name = db.Column(db.String(150))
    notes = db.relationship('Note')

#### If a user is new to the web application, they may need to register by filling out a registration form. This form typically requires users to provide personal information such as their name, email address, and a chosen username and password. Once the registration form is completed and submitted, the user will be redirected to the login page to access the application.

you can see it in the auth.py and signup.html

#### On the welcome page, users may have the option to access the main product of the application, which they can download by clicking on a link or button. Additionally, the welcome page may also contain other features such as about (of us, where is also a fake virus called Not_A_Virus.zip ;) ).


this part it in the welcome.py and auth.py

#### In the FINAL_PROJECT_DOWNLOAD.zip user can find three different tools (first Password Generator (to generate random and strong password; second Text Generator (there are the possibility to decrypt and encrypt the text);  Free DogGPT (which automatically responds in dog's language to any question). I made it by C# and XAML.

<Window x:Class="FINAL_PROJECT_DOWNLOAD.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        xmlns:local="clr-namespace:FINAL_PROJECT_DOWNLOAD"
        mc:Ignorable="d"
        Title="MainWindow"
        Height="500"
        Width="1000"
        WindowStyle="None"
        AllowsTransparency="True"
        Background="Transparent"
        WindowStartupLocation="CenterScreen">
    <Window.Resources>
        <ImageBrush x:Key="Assets" ImageSource="C:\Users\Namai\OneDrive\Desktop\ProjektasSUPER\loginscreen\loginscreen\Resources\2power.png"/>
        <Style x:Key="FocusVisual">
            <Setter Property="Control.Template">
                <Setter.Value>
                    <ControlTemplate>
                        <Rectangle Margin="2" StrokeDashArray="1 2" Stroke="{DynamicResource {x:Static SystemColors.ControlTextBrushKey}}" SnapsToDevicePixels="true" StrokeThickness="1"/>
                    </ControlTemplate>
                </Setter.Value>
            </Setter>
        </Style>
        <SolidColorBrush x:Key="Button.Static.Background" Color="#FFDDDDDD"/>
        <SolidColorBrush x:Key="Button.Static.Border" Color="#FF707070"/>
        <SolidColorBrush x:Key="Button.MouseOver.Background" Color="#FFBEE6FD"/>
        <SolidColorBrush x:Key="Button.MouseOver.Border" Color="#FF3C7FB1"/>
        <SolidColorBrush x:Key="Button.Pressed.Background" Color="#FFC4E5F6"/>
        <SolidColorBrush x:Key="Button.Pressed.Border" Color="#FF2C628B"/>
        <SolidColorBrush x:Key="Button.Disabled.Background" Color="#FFF4F4F4"/>
        <SolidColorBrush x:Key="Button.Disabled.Border" Color="#FFADB2B5"/>
        <SolidColorBrush x:Key="Button.Disabled.Foreground" Color="#FF838383"/>
        <Style x:Key="ButtonStyle1" TargetType="{x:Type Button}">
            <Setter Property="FocusVisualStyle" Value="{StaticResource FocusVisual}"/>
            <Setter Property="Background" Value="{StaticResource Button.Static.Background}"/>
            <Setter Property="BorderBrush" Value="{StaticResource Button.Static.Border}"/>
            <Setter Property="Foreground" Value="{DynamicResource {x:Static SystemColors.ControlTextBrushKey}}"/>
            <Setter Property="BorderThickness" Value="0"/>
            <Setter Property="HorizontalContentAlignment" Value="Center"/>
            <Setter Property="VerticalContentAlignment" Value="Center"/>
            <Setter Property="Padding" Value="1"/>
            <Setter Property="Template">
                <Setter.Value>
                    <ControlTemplate TargetType="{x:Type Button}">
                        <Border x:Name="border" Background="{TemplateBinding Background}" BorderBrush="{TemplateBinding BorderBrush}" BorderThickness="{TemplateBinding BorderThickness}" SnapsToDevicePixels="true">
                            <ContentPresenter x:Name="contentPresenter" Focusable="False" HorizontalAlignment="{TemplateBinding HorizontalContentAlignment}" Margin="{TemplateBinding Padding}" RecognizesAccessKey="True" SnapsToDevicePixels="{TemplateBinding SnapsToDevicePixels}" VerticalAlignment="{TemplateBinding VerticalContentAlignment}"/>
                        </Border>
                        <ControlTemplate.Triggers>
                            <Trigger Property="IsDefaulted" Value="true">
                                <Setter Property="BorderBrush" TargetName="border" Value="{DynamicResource {x:Static SystemColors.HighlightBrushKey}}"/>
                            </Trigger>
                            <Trigger Property="IsMouseOver" Value="true">
                                <Setter Property="Background" TargetName="border" Value="{StaticResource Assets}"/>
                                <Setter Property="BorderBrush" TargetName="border" Value="{StaticResource Button.MouseOver.Border}"/>
                            </Trigger>
                            <Trigger Property="IsPressed" Value="true">
                                <Setter Property="Background" TargetName="border" Value="{StaticResource Assets}"/>
                                <Setter Property="BorderBrush" TargetName="border" Value="{StaticResource Button.Pressed.Border}"/>
                            </Trigger>
                            <Trigger Property="IsEnabled" Value="false">
                                <Setter Property="Background" TargetName="border" Value="{StaticResource Button.Disabled.Background}"/>
                                <Setter Property="BorderBrush" TargetName="border" Value="{StaticResource Button.Disabled.Border}"/>
                                <Setter Property="TextElement.Foreground" TargetName="contentPresenter" Value="{StaticResource Button.Disabled.Foreground}"/>
                            </Trigger>
                        </ControlTemplate.Triggers>
                    </ControlTemplate>
                </Setter.Value>
            </Setter>
        </Style>
        <Style x:Key="FocusVisual1">
            <Setter Property="Control.Template">
                <Setter.Value>
                    <ControlTemplate>
                        <Rectangle Margin="2" StrokeDashArray="1 2" Stroke="{DynamicResource {x:Static SystemColors.ControlTextBrushKey}}" SnapsToDevicePixels="true" StrokeThickness="1"/>
                    </ControlTemplate>
                </Setter.Value>
            </Setter>
        </Style>



        <SolidColorBrush x:Key="Button.Static.Background1" Color="#FFDDDDDD"/>
        <SolidColorBrush x:Key="Button.Static.Border1" Color="#FF707070"/>
        <SolidColorBrush x:Key="Button.MouseOver.Background1" Color="#FFBEE6FD"/>
        <SolidColorBrush x:Key="Button.MouseOver.Border1" Color="#FF3C7FB1"/>
        <SolidColorBrush x:Key="Button.Pressed.Background1" Color="#FFC4E5F6"/>
        <SolidColorBrush x:Key="Button.Pressed.Border1" Color="#FF2C628B"/>
        <SolidColorBrush x:Key="Button.Disabled.Background1" Color="#FFF4F4F4"/>
        <SolidColorBrush x:Key="Button.Disabled.Border1" Color="#FFADB2B5"/>
        <SolidColorBrush x:Key="Button.Disabled.Foreground1" Color="#FF838383"/>
        <Style x:Key="ButtonStyle2" TargetType="{x:Type Button}">
            <Setter Property="FocusVisualStyle" Value="{StaticResource FocusVisual1}"/>
            <Setter Property="Background" Value="{StaticResource Button.Static.Background1}"/>
            <Setter Property="BorderBrush" Value="{StaticResource Button.Static.Border1}"/>
            <Setter Property="Foreground" Value="{DynamicResource {x:Static SystemColors.ControlTextBrush}}"/>
            <Setter Property="BorderThickness" Value="0"/>
            <Setter Property="HorizontalContentAlignment" Value="Center"/>
            <Setter Property="VerticalContentAlignment" Value="Center"/>
            <Setter Property="Padding" Value="1"/>
            <Setter Property="Template">
                <Setter.Value>
                    <ControlTemplate TargetType="{x:Type Button}">
                        <Border x:Name="border" CornerRadius="20" Background="{TemplateBinding Background}" BorderBrush="{TemplateBinding BorderBrush}" BorderThickness="{TemplateBinding BorderThickness}" SnapsToDevicePixels="true">
                            <ContentPresenter x:Name="contentPresenter" Focusable="False" HorizontalAlignment="{TemplateBinding HorizontalContentAlignment}" Margin="{TemplateBinding Padding}" RecognizesAccessKey="True" SnapsToDevicePixels="{TemplateBinding SnapsToDevicePixels}" VerticalAlignment="{TemplateBinding VerticalContentAlignment}"/>
                        </Border>
                        <ControlTemplate.Triggers>
                            <Trigger Property="IsDefaulted" Value="true">
                                <Setter Property="BorderBrush" TargetName="border" Value="{DynamicResource {x:Static SystemColors.HighlightBrushKey}}"/>
                            </Trigger>
                            <Trigger Property="IsMouseOver" Value="true">
                                <Setter Property="Background" TargetName="border" Value="#8B8000"/>
                                <Setter Property="BorderBrush" TargetName="border" Value="#8B8000"/>
                            </Trigger>
                            <Trigger Property="IsPressed" Value="true">
                                <Setter Property="Background" TargetName="border" Value="#7F00FF"/>
                                <Setter Property="BorderBrush" TargetName="border" Value="#7F00FF"/>
                            </Trigger>
                            <Trigger Property="IsEnabled" Value="false">
                                <Setter Property="Background" TargetName="border" Value="{StaticResource Button.Disabled.Background1}"/>
                                <Setter Property="BorderBrush" TargetName="border" Value="{StaticResource Button.Disabled.Border1}"/>
                                <Setter Property="TextElement.Foreground" TargetName="contentPresenter" Value="{StaticResource Button.Disabled.Foreground1}"/>
                            </Trigger>
                        </ControlTemplate.Triggers>
                    </ControlTemplate>
                </Setter.Value>
            </Setter>
        </Style>
    </Window.Resources>

    <Border CornerRadius="52" BorderThickness="10" BorderBrush="White">


        <Border CornerRadius="35" BorderThickness="20">
            <Border.BorderBrush>
                <LinearGradientBrush StartPoint="0,0" EndPoint="1,1">
                    <GradientStop Color="#F0EB36" Offset="0.0"/>
                    <GradientStop Color="#73C269" Offset="0.5"/>
                    <GradientStop Color="#1E91A5" Offset="1.0"/>
                </LinearGradientBrush>
            </Border.BorderBrush>

            <Grid>

                <Grid.Background>
                    <LinearGradientBrush StartPoint="0,0" EndPoint="1,1">
                        <GradientStop Color="#F0EB36" Offset="0.0"/>
                        <GradientStop Color="#73C269" Offset="0.5"/>
                        <GradientStop Color="#1E91A5" Offset="1.0"/>
                    </LinearGradientBrush>
                </Grid.Background>

                <Separator Margin="103,270,35,114" Height="50" Grid.Column="1" Background="DarkGoldenrod"/>
                <Image Source="C:\Users\Namai\OneDrive\Desktop\ProjektasSUPER\loginscreen\loginscreen\Resources\photo2.webp" Grid.Column="0" VerticalAlignment="Center"  />
                <Image Source="C:\Users\Namai\OneDrive\Desktop\ProjektasSUPER\loginscreen\loginscreen\Resources\photo2.webp" Grid.Column="1" VerticalAlignment="Center" />
                <Image Source="C:\Users\Namai\OneDrive\Desktop\ProjektasSUPER\loginscreen\loginscreen\Resources\photo2.webp" Grid.Column="2" VerticalAlignment="Center" />

                <Separator Margin="40,98,40,286" Height="50" Grid.Column="0"/>
                <Separator Margin="40,98,40,286" Height="50" Grid.Column="1"/>
                <Separator Margin="40,98,40,286" Height="50" Grid.Column="2"/>

                <Separator Margin="40,300,40,286" Height="50" Grid.Column="0"/>
                <Separator Margin="40,300,40,286" Height="50" Grid.Column="1"/>
                <Separator Margin="40,300,40,286" Height="50" Grid.Column="2"/>

                <Button Style="{DynamicResource ButtonStyle1}" x:Name="migtukas" Click="migtukas_Click" HorizontalAlignment="Right" VerticalAlignment="Top"
                     Padding="30"  BorderThickness="0" RenderTransformOrigin="1.236,0.304" BorderBrush="Transparent" Grid.Column="3" >
                    <Button.Background>
                        <ImageBrush ImageSource="C:\Users\Namai\OneDrive\Desktop\ProjektasSUPER\loginscreen\loginscreen\Resources\power.png" />
                    </Button.Background>

                </Button>

                <Button Style="{DynamicResource ButtonStyle2}" x:Name="passwordGenerator"   Grid.Column="0"  Content="Password&#x0a;Generator" Height="100"  FontSize="40"  VerticalAlignment="Center" HorizontalAlignment="Center"
                Background="DarkGoldenrod" Foreground="PapayaWhip" FontFamily="Cambria" BorderBrush="DarkGoldenrod" Click="Button_Click"  />

                <Button Style="{DynamicResource ButtonStyle2}" x:Name="TextGenerator"   Grid.Column="1"  Content="     Text&#x0a;Generator"  FontSize="40"  VerticalAlignment="Center" HorizontalAlignment="Center"
                Background="DarkGoldenrod" Foreground="PapayaWhip" FontFamily="Cambria" BorderBrush="DarkGoldenrod" Click="TextGenerator_Click"  />

                <Button Style="{DynamicResource ButtonStyle2}" x:Name="DogGPT"   Grid.Column="2"  Content="   Free&#x0a;DogGPT"  FontSize="40"  VerticalAlignment="Center" HorizontalAlignment="Center"
                Background="DarkGoldenrod" Foreground="PapayaWhip" FontFamily="Cambria" BorderBrush="DarkGoldenrod" Click="DogGPT_Click"/>
                <TextBlock Text="WELCOME" FontSize="60" Foreground="DarkGoldenrod"  Grid.Column="1" Grid.Row="0" HorizontalAlignment="Center" FontFamily="Cambria" FontStyle="Italic" FontWeight="Heavy" Margin="0,3,0,370" />
                <Grid.ColumnDefinitions>
                    <ColumnDefinition Width="*"/>
                    <ColumnDefinition Width="*"/>
                    <ColumnDefinition Width="*"/>
                </Grid.ColumnDefinitions>
            </Grid>

        </Border>
    </Border>
</Window>


## Overall, a web application with a login and registration form and a main product download on the welcome page is a common setup for many types of web applications, such as e-commerce sites, social media platforms, or productivity tools.
TODO

Viewing The App
Go to http://127.0.0.1:5000