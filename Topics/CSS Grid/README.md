# Hosted Project Site
[Hosted CSS Grid Project](https://akshay199456.github.io/100DaysOfCode-CSSGridProject/)
[GitHub Project Location](https://github.com/Akshay199456/100DaysOfCode-CSSGridProject)

## Description Of Project

The purpose of this project was to understand CSS grid and how the grid system could be utilized in order to make a page responsive as well as align elements within the grid. As a result, no JS was written to make the page functional (Might add it later when testing a new framework or JS concepts). It only contains HTML+CSS to create and align the elements. However, using the CSS Grid Layout has made the page responsive irrespective of the screen size used.

## Problems that I Ran Into

While using CSS Grid, the one issue you might run into is aligning the children of the grid items. Since the CSS Grid properties only apply to direct children, there are two possible solutions to this problem:

1. Create a grid system using **display: grid** on the grid element aligns the children of the grid element with respect to the grid element.
2. By using **display: contents**, the children of the grid element can be aligned with respect to the grid container itself.

## Useful Resources To Get Started With CSS Grid

1. [CSS Tricks](https://css-tricks.com/snippets/css/complete-guide-grid/#prop-grid-area) - Provides an in depth guide for each property that can be applied both to the grid parent and grid element.
2. [CSS Grid Garden](https://cssgridgarden.com/) - Game that allows you to test your CSS Grid skills