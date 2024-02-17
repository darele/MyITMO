package ru.itmo.web.hw4.util;

import ru.itmo.web.hw4.model.Colors;
import ru.itmo.web.hw4.model.Post;
import ru.itmo.web.hw4.model.User;

import javax.servlet.http.HttpServletRequest;
import java.util.Arrays;
import java.util.List;
import java.util.Map;

public class DataUtil {
    private static final List<User> USERS = Arrays.asList(
            new User(-1, "nulluser", "none", Colors.GREEN),
            new User(1, "MikeMirzayanov", "Mike Mirzayanov", Colors.GREEN),
            new User(6, "pashka", "Pavel Mavrin", Colors.RED),
            new User(9, "geranazavr555", "Georgiy Nazarov", Colors.GREEN),
            new User(11, "tourist", "Gennady Korotkevich", Colors.BLUE)
    );

    private static final List<Post> POSTS = Arrays.asList(
            new Post(0,1, "5 Best Linux Distros For Programming", "Linux’s distributions are highly recommended for web developers and programmers. The host operating system and web server on a Linux machine need to implement HTTP/HTTPS protocol and support Nginx, Apache, or any other suitable web server for that matter. What is a Linux distribution? A Linux distribution includes an embedded package management system, so it’s effortless to install additional software packages which can make your job easier; additionally, you can use any of the repositories from the different distributions present in the repositories section of their websites.", 5),
            new Post(1,6,"Achievement of Ayushman Bharat", "Ayushman Bharat, a government of India flagship program, was introduced as advised by the National Health Policy of 2017. The goal is to realize universal health coverage (UHC). This program was created to fulfill the Sustainable Development Goals (SDGs) and their core principle, “leave no one behind.” In an effort to transition from a sectoral and segmented strategy to the delivery of health services to a comprehensive need-based approach, Ayushman Bharat was created. With a focus on prevention, promotion, and ambulatory care at the primary, secondary, and tertiary levels of care, this program aspires to implement ground-breaking interventions. This scheme has approved by the Indian government in March 2018. It is an ambitious reform to the Indian health system that aims to provide financial health protection for 500 million of the most vulnerable Indians and stop the slide of the 50–60 million Indians who fall into poverty each year as a result of medical expenses. From April 2020 to July 2021, about 20.32 lakh Covid-19 tests and 7.08 lakh treatments were authorized under this scheme.\n" +
                    "\n" +
                    "The goal of the Ayushman Bharat Pradhan Mantri Jan Arogya Yojana is to lower catastrophic health costs. And to increase access to high-quality healthcare, lower unmet needs, and lower out-of-pocket healthcare costs for poor and vulnerable families in the State/Socio-Economic UT’s Caste Census (SECC) 2011 database as well as the estimated existing RSBY Beneficiary Families not included in the SECC database. To help impoverished and needy Indians, AB-PMJAY offers tertiary hospital care at an affordable price. More than 10 crore of the poorest and most vulnerable households in the nation are protected from financial danger thanks to Pradhan Mantri Jan Arogya Yojana, which also takes India one step closer to achieving universal health coverage.", 2),
            new Post(2, 9, "Shrinkflation", "Shrinkflation is a circumstance in which a product’s size “shrinks” or decreases even though its price stays the same. When a product’s size shrinks while its cost stays the same, this indicates that the product’s price is inflated and that the cost per unit of weight has grown. This approach is used by businesses as an alternative to raising prices right away because it has little to no impact on consumer indices like the consumer price index. However, a reduction in the size of the product actually causes prices to increase. Therefore, it represents a covert inflationary mechanism. Given that it may be viewed as less harsh than a price increase, it is frequently employed as a strategy to avoid raising costs and alienating customers. This phenomena, which was first described by the British economist Pippa Malmgren. It has gained popularity recently as a result of rising production and ingredient costs.", 12),
            new Post(3,11,"National Logistics Policy 2022", "The entire procedure of acquiring, storing, and delivering resources to their intended location is referred to as “logistics“. Among other things, it includes stock, tools, people, and raw materials. The National Logistics Policy was created to improve integration and cooperation between corporate entities, governmental organisations, and society at large in order to turn the Indian logistics industry into a significant driver of economic growth. The NLP strives to establish a thriving logistics ecosystem that encompasses all participants from many industries, including business, manufacturing, services, and agriculture. The NLP also offers a framework for supporting improved movement of commodities through contemporary transportation infrastructure across all modes of transportation, including roads, trains, waterways, etc., along with increasing the quality of traffic control systems. The goal of the strategy is to give multimodal connectivity infrastructure to various economic zones in addition to PM Modi’s Gati Shakti-National Master Plan, which was introduced in 2021. About eight years it took to develop NLP. Changes in policy and significant decisions are being taken to speed up last-mile delivery, put an end to transportation-related problems, save manufacturers time and money, and prevent the loss of agricultural products. Sector speed, value generation, and entrepreneurship will all increase when coordination is improved.\n" +
                    "\n" +
                    "Inaugurating the eagerly expected National Logistics Policy was Indian Prime Minister Narendra Modi on September 17, 2022. By offering a framework for creating a sustainable and successful logistics business, it seeks to accelerate the transformation of the Indian logistics industry. After expanding at a CAGR of 7.8 percent over the previous five years, Investment Information and Credit Rating Agency of India Limited (ICRA) predicts that the industry will expand at a CAGR of 10.5 percent through 2025. In India, this industry employs more than 22 million people, and it is predicted that through skill development, it would expand at a rate of 5% over the next five years. Recently, the government announced the National Logistics Policy (NLP) 2022, with the goal of achieving “rapid last-mile delivery” and resolving transportation-related issues.", 25),
            new Post(4, 1, "UPSC 2017 Prelims Questions and Answers", "UPSC 2017 Prelims Questions and Answers GS Paper I: On June 18, 2017, UPSC held General Studies Paper 1 as part of the Civil Services Prelims Exam 2017. There were 100 questions. The Civil Services Examination Prelims exam is the First level of the coveted and one of the country’s most rigorous tests. GeeksforGeeks have brought you the UPSC Previous Years Papers which will aid to prepare for the Upcoming UPSC Prelims Exam. Wish you all the Best!!\n" +
                    "\n" +
                    "Q1. With reference to the Parliament of India, consider the following statements:\n" +
                    "1. A private member’s bill is a bill presented by a Member of Parliament who is not elected but only nominated by the President of India.\n" +
                    "2. Recently, a private member’s bill has been passed in the Parliament of India for the first time in its history.\n" +
                    "Which of the statements given above is/are correct?\n" +
                    "a. 1 only\n" +
                    "b. 2 only\n" +
                    "c. Both 1 and 2\n" +
                    "d. Neither 1 nor 2\n" +
                    "Answer: d", 10),
            new Post(5, 11, "Computation of New Profit Sharing Ratio: Retirement of a Partner", "Whenever a partner retires from a firm, his/her share of profit is acquired either by all the remaining partners or some/ one of them. This leads to a change in Profit-Sharing Ratio among the continuing partners, and therefore, a New Profit-Sharing Ratio for each remaining partner is determined. A New Profit-Sharing Ratio in case of the retirement of a partner is a ratio in which continuing partners agree to share the future profits and losses. Due to the fact that the share of the retiring partner is acquired by all or some of the continuing partners, a New Profit-Sharing Ratio of the remaining partner is nothing but a sum total of the old share of the partner and the share acquired by the partner. Thus, New Share of a Partner = Old Share + Share Acquired by the Partner.", 40)
    );
    public static void addData(HttpServletRequest request, Map<String, Object> data) {
        data.put("users", USERS);
        data.put("posts", POSTS);

        for (User user : USERS) {
            if (Long.toString(user.getId()).equals(request.getParameter("logged_user_id"))) {
                data.put("user", user);
            }
        }
    }
}
