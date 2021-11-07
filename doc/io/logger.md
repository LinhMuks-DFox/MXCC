# `MXC::IO::Logger`

A simple logger implementation.  
logger will write the log to the specified file.

### Methods
The logger class has five main functions for logging.  
We classify log messages into four categories: 

* error:  that is, fatal errors.  
* info:   a message that outputs some information to the outside when the program is running.  
* debug:  which is used to record debug information during the development phase.  
* warn:   which suggests some information that is not fatal but very dangerous.  

For each type of error, we provide an interface with the same type name for logging the error.  
For fatal errors, there is a special method that logs the error while throwing an exception and closing the logger.  

1. `error(msg)`
2. `warn(msg)`
3. `info(msg)`
4. `debug(msg)`
5. `template<class Exp=Exp::LoggerError>log_and_raise_error(msg)`  

It is also possible to purely output information to the console. Although we don't recommend this, such an interface is provided. But to use these interfaces you also need to create a log file, even if it is a file that will not be written to anything.

1. `error_console(msg)`
2. `warn_console(msg)`
3. `info_console(msg)`
4. `debug_console(msg)`


These functions output a fixed format of log messages just like the main four interfaces, except that these functions output the messages to the console.

It is also possible to output messages to `std::ostream`, but in this case you need to specify the type of the output message.
* `log_to_std_ostream(const std::ostream& ost, const gl_str& content, LogType type)`



Of course, in addition to support for logging different kinds of errors, custom log formats are also supported.  

The `set_format(const gl_str& str)` function can be used to set the log format.(in current version, `gl_str` aka `std::string`)
* `set_format(const gl_str& str)`  
  This function accepts a C-like style string format. Use the `%` symbol to indicate the format.
  
  1. `%t`,Used to specify the type`{FATAL, INFO, WARN, DEBUG}` of log.
  2. `%Y`, Used to specify the Year(1900~Now).
  3. `%M`, Used to specify the Month(1~12).
  4. `%D`, Used to specify the Day(1~31).
  5. `%H`, Used to specify the Hour(0~23).
  6. `%m`, Used to specify the Minutes(0~59).
  7. `%s`, Used to specify the Seconds(0~59).
  8. `%c`, Used to specify the Log content(passed by user).
  
  In case **no log format is specifically specified**, the:
  
  `[%t]time:<%Y-%M-%D %H:%m:%s>,content:%c `
  
  format will be automatically used.
  
  An example of its log format:
  
  `[FATAL]time:<2021-11-7 20:52:21>,content:!!This is a error!! `

### how to use?

```C++
#include <logger.hpp>
int main() {
    MXC::IO::Logger my_logger("log_path.log");
    logger.error("An error occurred, program crashed down.");
    logger.warn("An illegitimate parameter is forced to be passed in.");
    return 0;
}
```

```text
output(content in log_path.loh):
[FATAL]time:<2021-11-7 20:54:37>,content:An error occurred, program crashed down. 
[WARN]time:<2021-11-7 20:54:37>,content:An illegitimate parameter is forced to be passed in. 

```

Of course you can also specify a logger in your project for global logging, similar to `cout`, `clog`, etc.
