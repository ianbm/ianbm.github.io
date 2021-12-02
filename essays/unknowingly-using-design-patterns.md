---
layout: essay
type: essay
title: Unknowingly using Design Patterns
date: 2021-12-01
labels:
- design patterns
---
## When you learn something that you already know...
We all heard the phrase: "Practice makes perfect." Or in other words, it means that the more you practice an activity, the better you get at it. I've been programming for a few years now, and have used design patterns regularly. So I guess you could say that I'm pretty experienced when it comes to design patterns. The funny thing is, I've never even heard of the phrase "design pattern" until recently.

<img src="/images/design-patterns-meme.jpg" width="100" alt="Design Patterns">

So what is a design pattern? It's a reusable solution to recurring problems in software design. It's sort of like a template. These are especially helpful for new programmers.

## Did I really just do that?
The first thing that came to mind when I learned about design patterns is our final project for ICS 314 which involves creating a functional application using what we learned throughout the semester. Our final project used a template that was provided by the professor. This was especially helpful for me because there were concepts like prototypes and routers, which were all new to me and a bit confusing at first. Now, if we break it down even further, we can see some of the design patterns that we used for the project. Keep in mind that most of the code was done without know what a design pattern is. You can view the final project on [GitHub](https://github.com/surf-connect/surf-connect). Here are some examples of design patterns we used in the final project:

### Observer (Publish-Subscribe)
This design pattern helps software designers display only certain data pieces of data to the users. Our final project has a user page where we want to display only the logged in user's profile. This user page would need a subscription in order to access the user data. In our final project, you can view all the publications in the [Publications.js](https://github.com/surf-connect/surf-connect/blob/master/app/imports/startup/server/Publications.js) file.

### Singleton
The project uses a singleton global variable to allow collections to be accessed throughout the application. We have a global variable called Users which can be found in the [Users.js](https://github.com/surf-connect/surf-connect/blob/master/app/imports/api/user/Users.js) file. This global variable is used in the user page when creating the subscription.

## Final thoughts on Design Patterns
I think design patterns are great. The biggest reason to use them at all (in my opinion) is that they are already proven to work. When programming, using a template makes things easier and quicker.