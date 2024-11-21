const core = require('@actions/core');
const github = require('@actions/github');

async function run() {
    try {
        // Get inputs from action.yml
        const issueUrl = core.getInput('issue-url');
        const commentBody = core.getInput('comment-body');
        const token = core.getInput('token');

        // Log the inputs
        console.log(`Posting comment to: ${issueUrl}`);
        console.log(`Comment: ${commentBody}`);

        // Create a GitHub client
        const octokit = github.getOctokit(token);

        //OPTION_1: Post the comment using GitHub's API (request)
        const response = await octokit.request('POST {url}/comments', {
            url: issueUrl,
            body: commentBody,
        });

        // //OPTION_2: Post the comment using GitHub's Higher level API (rest.issues)
        // const { owner, repo } = github.context.repo;
        // const issueNumber = issueUrl.split('/').pop();

        // const response = await octokit.rest.issues.createComment({
        //     owner: owner,
        //     repo: repo,
        //     issue_number: issueNumber,
        //     body: commentBody,
        // });

        // Log success message
        console.log('Comment posted successfully:', response.data);
    } catch (error) {
        core.setFailed(`Action failed with error: ${error.message}`);
    }
}

run();


//Optional: compile with vercel (npm @vercel/ncc)
//ncc build index.js --license licenses.txt --minify